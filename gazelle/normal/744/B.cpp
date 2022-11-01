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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> ans(n,INF*INF);
	REP(i,10) {
		vector<ll> res;
		FOR(j,1,n+1) {
			bitset<10> bi(j);
			if(bi[i]==1) res.pb(j);
		}
		if((ll)res.size()==0) continue;
		cout<<(ll)res.size()<<endl;
		DUMP(res);
		vector<ll> buf(n);
		REP(j,n) cin>>buf[j];
		REP(j,n) {
			bitset<10> bi(j+1);
			if(bi[i]==0) ans[j]=min(ans[j],buf[j]);
		}
	}
	REP(i,10) {
		vector<ll> res;
		FOR(j,1,n+1) {
			bitset<10> bi(j);
			if(bi[i]==0) res.pb(j);
		}
		if((ll)res.size()==0) continue;
		cout<<(ll)res.size()<<endl;
		DUMP(res);
		vector<ll> buf(n);
		REP(j,n) cin>>buf[j];
		REP(j,n) {
			bitset<10> bi(j+1);
			if(bi[i]==1) ans[j]=min(ans[j],buf[j]);
		}
	}
	cout<<-1<<endl;
	DUMP(ans);
}