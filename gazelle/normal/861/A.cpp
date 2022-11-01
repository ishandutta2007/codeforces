#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	int c2=0,c5=0;
	ll buf=n;
	while(buf%2==0) {
		++c2;
		buf/=2;
	}
	buf=n;
	while(buf%5==0) {
		++c5;
		buf/=5;
	}
	int res2=max((ll)0,k-c2);
	int res5=max((ll)0,k-c5);
	ll res=n;
	REP(i,res2) res*=2;
	REP(i,res5) res*=5;
	cout<<res<<endl;
}