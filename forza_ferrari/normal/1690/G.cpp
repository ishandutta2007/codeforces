#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
inline char gc(){
	char ch;
	while(!isupper(ch=getchar()));
	return ch;
}
template<class T>
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],m,n,t_case;
typedef pair<int,int> pii;
#define l first
#define r second
struct cmp{inline bool operator()(const pii &x,const pii &y)const{return x.r<y.r;}};
int main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr();
		set<pii,cmp>s;
		for(ri i=1;i<=n;++i)a[i]=qr();
		ri lst=1;
		for(ri i=1;i<=n;++i)
			if(a[i]<a[lst])
				s.emplace(lst,i-1),lst=i;
		s.emplace(lst,n);
		while(m--){
			ri x=qr(),y=qr();
			auto it=s.lower_bound({x,x});
			assert(it!=s.end());
			ri L=it->l,R=it->r;
			if(a[x]-y<a[L]){
				it=s.erase(it);
				if(L<x)it=s.emplace(L,x-1).first,++it;
			}
			else{a[x]-=y,qw(s.size()),putchar(32);continue;}
			a[x]-=y;
			for(;it!=s.end()&&a[it->l]>=a[x];R=it->r,it=s.erase(it));
			s.emplace(x,R);
			qw(s.size()),putchar(32);
		}
		putchar(10);
	}
	return 0;
}