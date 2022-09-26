#include<bits/stdc++.h>
using namespace std;
#define N 1000050
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
int f[N],g[N];
char a[N],b[N],s[N];
ll ans;
struct BIT{
	ll b[N];
	inline int lowbit(int x){return x&(-x);}
	inline ll Ask(int x){
		ll ans=0;
		while(x<=m)ans+=b[x],x+=lowbit(x);
		return ans;
	}
	inline void Add(int x,int d){
		while(x)b[x]+=d,x-=lowbit(x);
	}
}B0,B1;
int z[N];
void Z(char *s,int n){
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;++i){
		z[i]=0;
		if(i<=r)z[i]=min(r-i+1,z[i-l+1]);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
void exkmp(char *s,char *t,int n,int m,int *p){
	Z(t,m);
	for(int i=1,l=0,r=0;i<=n;++i){
		if(i<=r)p[i]=min(r-i+1,z[i-l+1]);
		while(i+p[i]<=n&&p[i]+1<=m&&s[i+p[i]]==t[p[i]+1])++p[i];
		if(i+p[i]-1>r)l=i,r=i+p[i]-1;
	}
}
int main(){
	n=read(),m=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",s+1);
	exkmp(a,s,n,m,f);
	reverse(b+1,b+n+1);
	reverse(s+1,s+m+1);
	exkmp(b,s,n,m,g);
	reverse(g+1,g+n+1);
	for(int i=1;i<=n;++i)f[i]=min(f[i],m-1),g[i]=min(g[i],m-1);
	for(int i=1;i<=min(n,m-1);++i){
		B0.Add(g[i],1);
		B1.Add(g[i],g[i]);
	}
	for(int i=1;i<=n;++i){
		ans+=B1.Ask(m-f[i])+1LL*B0.Ask(m-f[i])*(f[i]-m+1);
		B0.Add(g[i],-1);
		B1.Add(g[i],-g[i]);
		if(i+m-1<=n){
			B0.Add(g[i+m-1],1);
			B1.Add(g[i+m-1],g[i+m-1]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}