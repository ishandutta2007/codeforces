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
const ll inf=1e18;
ll x[N],y[N];bool v[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld%lld",&x[i],&y[i]);
	int s=1;v[1]=1;printf("1");
	rep(i,2,n){int t=0;ll d=0;
		rep(j,1,n)if(!v[j]){
			ll dis=(x[s]-x[j])*(x[s]-x[j])+(y[s]-y[j])*(y[s]-y[j]);
			if(dis>d){
				d=dis;t=j;
			}
		}
		v[t]=1;printf(" %d",s=t);
	}
}