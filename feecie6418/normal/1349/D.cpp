#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//F[i]:i
//P[i]:i 
//G[i]:i
//H[x]:x 
//sum(p[i])=1
//G[i]=sum_j(F[j]+P[j]Cost[i,j]) --- *
//Cost[i,j]ji
//i=j:cost[i,j]=0  Otherwise:cost[i][j]=H[0]
//* 
//sum_i(H[a[i]])=sum_i(n*F[i]+(n-1)H[0])
//ans=sum(F[i])=sum_i(H[a[i]])-(n-1)H[0]
//F
const int mod=998244353;
int n,a[100005],h0,ans=0,m=0;
int Power(int x,int y) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
struct P{
	int k,x;
}h[300005];//h[i]=k*h[0]+x
P operator +(P i,P j){return {(i.k+j.k)%mod,(i.x+j.x)%mod};} 
P operator -(P i,P j){return {(i.k-j.k+mod)%mod,(i.x-j.x+mod)%mod};}
P operator *(ll j,P i){return {1ll*i.k*j%mod,1ll*i.x*j%mod};}
int main(){
	scanf("%d",&n),h[0]={1,0},h[1]={1,(mod-n+1)%mod};
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m+=a[i];
	for(int i=1;i<m;i++)h[i+1]=(ll)Power(m-i,mod-2)*((P){0,1ll*m*(1-n+mod)%mod}+(m+1ll*(n-2)*i)%mod*h[i]-1ll*i*(n-1)%mod*h[i-1]);
	h0=1ll*(mod-h[m].x)*Power(h[m].k,mod-2)%mod;
	for(int i=1;i<=n;i++)ans=(ans+1ll*h[a[i]].k*h0+h[a[i]].x)%mod;
	printf("%lld\n",(ans-1ll*(n-1)*h0%mod+mod)%mod*Power(n,mod-2)%mod);
	return 0;
}
/*
2
1 1
out:1

*/