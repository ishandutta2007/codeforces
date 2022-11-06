#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
int main(){int n;ll ns=0;double nw=0;
	scanf("%d",&n);
	rep(i,1,n){double x;
		scanf("%lf",&x);nw+=x;
		ll r=round(nw)-ns;
		printf("%lld\n",r);ns+=r;
	}
}