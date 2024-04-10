#include <bits/stdc++.h>
#define ll long long
int f[31],ans,n,mod;

void solve(){
	ans=0;
	scanf("%d%d",&n,&mod);
	std::memset(f,0,sizeof(f));
	int lim=1;while((1<<lim)<=n)lim++;
	for(int i=1;i<=lim;++i){
		int mask;
		if(i!=lim)mask=(1<<(i-1))%mod;
		else mask=(n-(1<<(lim-1))+1)%mod;
		f[i]=mask;
		for(int j=1;j<i;++j)
			f[i]=(f[i]+(ll)f[j]*mask%mod)%mod;
		ans=(ans+f[i])%mod;
	}printf("%d\n",ans);
}
			
	

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}