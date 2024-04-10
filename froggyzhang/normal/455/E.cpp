#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const ll inf=2e18;


#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		std::vector<int> num;
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (; x; x /= 10) {
			num.push_back(x % 10);
		}
		while (!num.empty()) {
			putchar(num.back() ^ '0');
			num.pop_back();
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

int n,a[N],Q,b[N],len;
ll ans[N],s[N];
vector<pair<int,int> > q[N];
struct Line{
	ll k,b;
	Line(ll _k=inf,ll _b=inf){k=_k,b=_b;}
	inline ll Val(ll x){
		return k==inf?inf:k*x+b;
	}
};
struct node{
	int ch[2];
	Line z;
}t[N<<2];
#define ls u<<1
#define rs u<<1|1
vector<pair<int,Line> > vec[N];
void Insert(int u,int L,int R,Line p,int id){
	if(L==R){
		if(t[u].z.Val(b[L])>p.Val(b[L])){
			vec[id].emplace_back(u,t[u].z);
			t[u].z=p;
		}
		return;
	}
	int mid=(L+R)>>1;
	if(t[u].z.k>p.k){	
		if(t[u].z.Val(b[mid])>p.Val(b[mid])){
			Insert(ls,L,mid,t[u].z,id);
			vec[id].emplace_back(u,t[u].z);
			t[u].z=p;	
		}
		else{
			Insert(rs,mid+1,R,p,id);
		}
	}
	else{
		if(t[u].z.Val(b[mid])>p.Val(b[mid])){
			Insert(rs,mid+1,R,t[u].z,id);
			vec[id].emplace_back(u,t[u].z);
			t[u].z=p;
		}
		else{
			Insert(ls,L,mid,p,id);
		}
	}
}
ll Query(int u,int L,int R,int p){
	if(L==R)return t[u].z.Val(b[p]);
	int mid=(L+R)>>1;
	ll mn=t[u].z.Val(b[p]);
	if(p<=mid)mn=min(mn,Query(ls,L,mid,p));
	else mn=min(mn,Query(rs,mid+1,R,p));
	return mn;
}
inline void Del(int x){
	for(auto myh:vec[x]){
		int u=myh.first;
		t[u].z=myh.second;
	}	
}
int main(){
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	read(Q);
	for(int i=1;i<=Q;++i){
		int x,y;
		read(x),read(y);
		q[y].emplace_back(x,i);
		b[++len]=x-y;
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;++i){
		static int st[N],top;
		while(top&&a[i]<a[st[top]])Del(st[top--]);
		Insert(1,1,len,Line(a[i],-s[i]+1LL*i*a[i]),i);
		st[++top]=i;
		for(auto zyk:q[i]){
			int x=zyk.first,id=zyk.second;
			int p=lower_bound(b+1,b+len+1,x-i)-b;
			ans[id]=Query(1,1,len,p)+s[i];
		}
	}
	for(int i=1;i<=Q;++i){
		print(ans[i]);
	}
	return 0;
}