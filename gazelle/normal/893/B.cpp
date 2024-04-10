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
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

bool det(ll n) {
	ll bit=0;
	ll buf=n;
	while(buf>0) {
		bit++;
		buf/=2;
	}
	if(bit%2==0) return false;
	buf=n;
	REP(i,bit/2) {
		if(buf%2==1) return false;
		buf/=2;
	}
	REP(i,bit/2+1) {
		if(buf%2==0) return false;
		buf/=2;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	for(ll i=n; i>=1; i--) {
		if(n%i==0&&det(i)) {
			cout<<i<<endl;
			return 0;
		}
	}
}