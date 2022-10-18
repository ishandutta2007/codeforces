#include <bits/stdc++.h>
#define ll long long
int t,n[4],rk[4];
ll ans,a[4][100005];
ll sqr(ll x){return x*x;}

int main(){
    scanf("%d",&t);
    for(;t;t--){
        ans=9e18;
    	scanf("%d%d%d",&n[1],&n[2],&n[3]);
    	for(int i=1;i<=3;++i){
    		for(int j=1;j<=n[i];++j)
    			scanf("%lld",&a[i][j]);
    		std::sort(a[i]+1,a[i]+n[i]+1);
    		rk[i]=i;
    	}do{
    		int prv=0,nxt=1;
    		for(int i=1;i<=n[rk[2]];++i){
    			while(prv<n[rk[1]]&&a[rk[1]][prv+1]<=a[rk[2]][i])prv++;
    			while(nxt<=n[rk[3]]&&a[rk[3]][nxt]<a[rk[2]][i])nxt++;
    			if(nxt>n[rk[3]])break;
    			if(prv==0)continue;
    			ans=std::min(ans,
    			sqr(a[rk[1]][prv]-a[rk[2]][i])+
    			sqr(a[rk[1]][prv]-a[rk[3]][nxt])+
    			sqr(a[rk[2]][i]-a[rk[3]][nxt]));
    		}
    	}while(std::next_permutation(rk+1,rk+4));
    	printf("%lld\n",ans);
    }
	return 0;
}