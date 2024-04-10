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
#include<bitset>
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

bool d(ll n) {
	string s=to_string(n);
	bool hoge=true;
	REP(i,(ll)s.size()) {
		if(s[i]!='9') hoge=false;
	}
	return hoge;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	string ns=to_string(n);
	ll ans=0;
	if(ns[0]>='5') {
		ll a=5;
		REP(i,(ll)ns.size()-1) a*=10;
		ans=n-a+1;
		if(d(n)) ans--;

	} else {
		if((ll)ns.size()==1) {
			cout<<n*(n-1)/2<<endl;
			return 0;
		}
		ll a=stol(ns.substr(1,(ll)ns.size()-1));
		ll b=5;
		REP(i,(ll)ns.size()-2) b*=10;
		if(a>=b) {
			ans=(ll)((ns[0]-'0')+1)*(ll)((ns[0]-'0')+1)*(a-b+1)+(ll)((ns[0]-'0'))*(ll)((ns[0]-'0')+1)*(b-(a-b+1));
			if(d(a)) {
				ans-=(ll)((ns[0]-'0')+1);
			}
			else ans-=(ll)((ns[0]-'0'));
		} else {
			ans=(ll)((ns[0]-'0'))*(ll)((ns[0]-'0'))*(b-a-1)+(ll)((ns[0]-'0'))*(ll)((ns[0]-'0')+1)*(b-(b-a-1))-(ll)((ns[0]-'0'));
		}
	}
	cout<<ans<<endl;

}