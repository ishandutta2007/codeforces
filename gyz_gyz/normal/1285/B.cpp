#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=1e6+10;
ll a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	ll nw=0,mi=1e18,res=-1e18;
	rep(i,1,n){
		nw+=a[i];
		if(i<n)res=max(res,nw);
		res=max(res,nw-mi);
		mi=min(mi,nw);
	}
	printf("%s\n",nw>res?"YES":"NO");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}