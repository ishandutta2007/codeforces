#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const ll inf=1e18;
const int mo=998244353;
int s[N];
ll cal(ll x,int n){
	return x/n*s[n-1]+s[x%n];
}
void sol(){int a,b,q;
	scanf("%d%d%d",&a,&b,&q);
	rep(i,1,a*b-1)s[i]=s[i-1]+(i%a%b!=i%b%a);
	rep(i,1,q){ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld ",cal(r,a*b)-cal(l-1,a*b));
	}printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}