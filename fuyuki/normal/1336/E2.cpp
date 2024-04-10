#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define cnt(x) __builtin_popcountll(x)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+1,M=64,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
int n,k,m,tot;
ll a[N],f[M],g[M],t[M];
int ans[M],tmp[M],pw[N],c[M][M],w[M][M];
V ins(ll x){
	ROF(i,m,0)if(x>>i&1){
		if(f[i])x^=f[i];
		else return f[i]=x,k++,void();
	}
}
V dfs(int p,ll x){
	if(p==tot)tmp[cnt(x)]++;
	else dfs(p+1,x),dfs(p+1,x^t[p]);
}
int main(){
	cin.tie(0),cin>>n>>m,pw[0]=1,m--;
	FOR(i,1,n)cin>>a[i],ins(a[i]),check(pw[i]=pw[i-1]<<1);
	FOR(i,0,m)FOR(j,0,i-1)if(f[i]>>j&1)f[i]^=f[j];
	if(k<=26){
		FOR(i,0,m)if(f[i])t[tot++]=f[i];
		dfs(0,0);
		FOR(i,0,m+1)cout<<1ll*pw[n-k]*tmp[i]%mod<<' ';
	}
	else{
		FOR(i,0,m)FOR(j,0,m)g[j]|=(f[i]>>j&1)<<i;
		FOR(i,0,m)if(g[i]^=1ll<<i)t[tot++]=g[i];
		k=++m-k,dfs(0,0);
		FOR(i,0,m)c[i][0]=1;
		FOR(i,1,m)FOR(j,1,m)check(c[i][j]=c[i-1][j]+c[i-1][j-1]);
		FOR(i,0,m)FOR(j,0,m)FOR(p,0,i)
			if(p&1)check(w[i][j]+=mod-1ll*c[j][p]*c[m-j][i-p]%mod);
			else check(w[i][j]+=1ll*c[j][p]*c[m-j][i-p]%mod);
		FOR(i,0,m)FOR(j,0,m)
			check(ans[i]+=1ll*tmp[j]*w[i][j]%mod);
		int tag=pw[max(0,n-m+k)];
		FOR(i,1,k)tag=1ll*(mod+1>>1)*tag%mod;
		FOR(i,0,m)cout<<1ll*ans[i]*tag%mod<<' ';
	}
	return 0;
}