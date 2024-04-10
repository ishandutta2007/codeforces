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
#include<random>
#include<time.h>
#include<fstream>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	REP(i,n) {
		REP(j,(ll)a.size()-1) {
			if(abs(a[j]-a[j+1])>=2) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
		ll pos=0;
		ll buf=0;
		REP(j,(ll)a.size()) {
			if(a[j]>buf) {
				pos=j;
				buf=a[j];
			}
		}
		a.erase(a.begin()+pos);
	}
	cout<<"YES"<<endl;
}