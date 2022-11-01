#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
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
	vector<pair<P,ll>> b(n);
	REP(i,n) b[i].second=a[i];
	REP(i,n) {
		ll c2=0,c3=0;
		ll buf=b[i].second;
		while(buf%2==0) {
			c2++;
			buf/=2;
		}
		buf=b[i].second;
		while(buf%3==0) {
			c3++;
			buf/=3;
		}
		b[i].first.first=-c3;
		b[i].first.second=c2;
	}
	sort(ALL(b));
	REP(i,n) {
		cout<<b[i].second;
		if(i==n-1) cout<<endl;
		else cout<<" ";
	}
}