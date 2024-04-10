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
const int N=2e6+10;
const int mo=998244353;
int main(){ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	printf("%lld %lld\n",(n+m)/k,n%k+m%k<k?0:k-max(n%k,m%k));
}