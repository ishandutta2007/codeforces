#include<bits/stdc++.h>
using namespace std;
const int N=5000000,mod=1000000007;
typedef long long LL;
bool np[N+5];
int minp[N+5],p[N],tot;
int f[N+5];
void init(){
	int k;
	for(int i=2;i<=N;i++){
		if(!np[i])p[++tot]=i,f[i]=1LL*(i-1)*i/2%mod,minp[i]=i;
		for(int j=1;j<=tot&&i*p[j]<=N;j++){
			np[i*p[j]]=1;
			minp[i*p[j]]=min(p[j],minp[i]);
			f[i*p[j]]=(1LL*f[p[j]]*i+f[i])%mod;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	init();
	LL ans=0;
	int l,r,t,now=1;
	scanf("%d%d%d",&t,&l,&r);
	for(int i=l;i<=r;i++){
		ans+=1LL*now*f[i]%mod;
		now=1LL*now*t%mod;
	}
	cout<<ans%mod<<endl;
}