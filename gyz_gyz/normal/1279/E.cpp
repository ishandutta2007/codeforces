#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll inf=1e18+1;
int n,ans[51],t[51];
ll k,fac[51],dp[51];bool v[51];
ll mul(ll x,ll y){return !x?0:inf/x<y?inf:x*y;}
ll cal(int x){return x<2?1:fac[x-2];}
void work(int l,int r){
	rep(i,l,r)t[i]=i,v[i]=0; 
	ans[l]=r;v[r]=1;swap(t[l],t[r]);
	rep(i,l+1,r-1){
		rep(j,l,r)if(!v[j]&&i!=t[j]){
			if(mul(fac[r-i-1],dp[n-r])>=k){
				ans[i]=j;v[j]=1;
				int x=t[i],y=t[j];
				t[x]=y;t[y]=x;break;
			}else k-=mul(fac[r-i-1],dp[n-r]);
		}
	}
	ans[r]=t[r];
}
void sol(){
	scanf("%d%lld",&n,&k);
	if(dp[n]<k)return(void)printf("-1\n");
	int nw=1;
	while(nw<=n)rep(i,1,n-nw+1){
		if(mul(cal(i),dp[n-nw-i+1])>=k){
			work(nw,nw+i-1);
			nw+=i;break;
		}else k-=mul(cal(i),dp[n-nw-i+1]);
	}
	rep(i,1,n)printf("%d%c",ans[i],i==n?'\n':' ');
}
int main(){int t;
	fac[0]=1;dp[0]=1;
	rep(i,1,50)fac[i]=mul(fac[i-1],i);
	rep(i,1,50)rep(j,1,i)dp[i]=min(inf,dp[i]+mul(dp[i-j],cal(j)));
	scanf("%d",&t);
	rep(i,1,t)sol();
}