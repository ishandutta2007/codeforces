#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<20,M=22,mod=998244353,INF=0x3f3f3f3f;
char st[M][N];
int n,m,ans,a[N],f[N],g[N];
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",st[i]+1);
}
V init(){
	FOR(i,1,m)FOR(j,1,n)a[i]=a[i]<<1|st[j][i]-'0';
	FOR(i,1,m)f[a[i]]++;
	m=1<<n;
	FOR(i,1,m-1)g[i]=g[i>>1]+(i&1);
	FOR(i,1,m-1)g[i]=min(g[i],n-g[i]);
}
V check(int&x){x-=mod-x>>31&mod;}
V FWT(int*a,int l){
	for(int i=1,t;i<l;i<<=1)for(int j=0,d=i<<1;j<l;j+=d)FOR(k,0,i-1)
		t=a[i|j|k],check(a[i|j|k]=a[j|k]+mod-t),check(a[j|k]+=t);
}
V IFWT(int*a,int l){
	FWT(a,l);int bk(mod-mod/l);
	FOR(i,0,l-1)a[i]=1ll*a[i]*bk%mod;
}
V work(){
	FWT(f,m),FWT(g,m);
	FOR(i,0,m-1)f[i]=1ll*f[i]*g[i]%mod;
	IFWT(f,m),ans=INF;
	FOR(i,0,m-1)ans=min(ans,f[i]);
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}