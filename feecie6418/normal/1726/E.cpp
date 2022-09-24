#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=300000;
int f[N+5],g[N+5],jc[N+5],ny[N+5];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	jc[0]=ny[0]=f[0]=f[1]=g[0]=1;
	for(int i=1;i<=N;i++){
		jc[i]=1ll*jc[i-1]*i%mod;
		if(i>1)f[i]=(f[i-1]+1ll*(i-1)*f[i-2])%mod;
		if(i%2==0)g[i]=1ll*(i-1)*g[i-2]%mod;
	}
	ny[N]=Power(jc[N],mod-2);
	for(int i=N-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		scanf("%d",&n);
		for(int i=0;i*4<=n;i++){
			int w=1ll*Power(2,i)*g[2*i]%mod;
			w=1ll*w*f[n-i*4]%mod;
			w=1ll*w*C(n-i*4+i*2,i*2)%mod; 
			ans=(ans+w)%mod;
		}
		printf("%d\n",ans);
	}
}