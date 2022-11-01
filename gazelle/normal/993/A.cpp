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
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
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
	vector<P> sq1(4);
	vector<P> sq2(4);
	REP(i,4) cin>>sq1[i].first>>sq1[i].second;
	REP(i,4) cin>>sq2[i].first>>sq2[i].second;
	REP(i,4) {
		sq1[i].first*=2;
		sq1[i].second*=2;
		sq2[i].first*=2;
		sq2[i].second*=2;
	}
	P cnt1=P((sq1[0].first+sq1[3].first)/2,(sq1[0].second+sq1[3].second)/2);
	P cnt2=P((sq2[0].first+sq2[3].first)/2,(sq2[0].second+sq2[3].second)/2);
	sort(ALL(sq1));
	sort(ALL(sq2));
	sq1.pb(cnt1);
	sq2.pb(cnt2);
	bool d=false;
	REP(i,5) {
		if(sq2[i].first>=sq1[0].first&&sq2[i].first<=sq1[2].first&&sq2[i].second>=sq1[0].second&&
		   sq2[i].second<=sq1[1].second) {
			d=true;
		}
	}
	P cnt=P((sq2[0].first+sq2[3].first)/2,(sq2[0].second+sq2[3].second)/2);
	REP(i,5) {
		if(abs(sq1[i].first-cnt.first)+abs(sq1[i].second-cnt.second)<=abs(sq2[0].first-cnt.first)
		   +abs(sq2[0].second-cnt.second)) {
			d=true;
		}
	}
	if(d) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}