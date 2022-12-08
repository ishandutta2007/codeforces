#include<bits/stdc++.h>
using namespace std;
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline long long read() {
	long long x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int maxn=200010;
struct Tree {
	vector<int>s[maxn];
	void add(int a,int b) {
		s[a].push_back(b);
		s[b].push_back(a);
	}
}A,B;
int v[maxn],f[maxn],ans,cnt;
void dfs(int x,int fa,int c) {
	for(int y:A.s[x]) {
		if(y==fa)continue;
		if(v[x]!=v[y]) {
			B.add(c,++cnt);
			dfs(y,x,cnt);
		}
		else dfs(y,x,c);
	}
}
void dp(int x,int fa) {
	for(int y:B.s[x]) {
		if(y==fa)continue;
		dp(y,x);
		ans=max(ans,f[x]+f[y]+1);
		f[x]=max(f[x],f[y]+1);
	}
}
int main() {
	int n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<n;i++) {
		int a=read(),b=read();
		A.add(a,b);
	}
	dfs(1,0,cnt=1);
	dp(1,0);
	printf("%d\n",(ans+1)/2);
	return 0;
}