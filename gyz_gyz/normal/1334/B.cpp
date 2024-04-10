#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18;
const int mo=998244353;
ll a[N];
bool cmp(ll x,ll y){return x>y;}
void sol(){int n;ll m,tot=0;
	scanf("%d%lld",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	rep(i,1,n){
		tot+=a[i];
		if(m*i>tot){
			printf("%d\n",i-1);return;
		}
	}
	printf("%d\n",n);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}