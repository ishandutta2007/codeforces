#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=998244353;
ll a[N];
int main(){int n,q;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)a[i]+=a[i-1];
	scanf("%d",&q);
	rep(i,1,q){int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",(a[r]-a[l-1])/10);
	}
}