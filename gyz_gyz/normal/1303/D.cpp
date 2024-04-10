#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
ll v[33];
void sol(){ll n;int m;
	scanf("%lld%d",&n,&m);
	rep(i,0,32)v[i]=0;
	rep(i,1,m){ll x;
		scanf("%lld",&x);
		rep(j,0,32)if(x>>j==1){
			++v[j];break;
		}
	}ll tot=0;
	rep(i,0,32)tot+=v[i]<<i;
	if(tot<n){
		printf("-1\n");return;
	}int ans=0;
	rep(i,0,32)if((n>>i)&1){
		if(!v[i])rep(j,i+1,32)if(v[j]){
			dep(k,j,i+1){
				--v[k];v[k-1]+=2;++ans;
			}break;
		}
		v[i+1]+=(v[i]-1)/2;
	}else v[i+1]+=v[i]/2;
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}