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
	ll n,m,r,k;
	cin>>n>>m>>r>>k;
	vector<ll> tate(n+1);
	vector<ll> yoko(m+1);
	REP(i,n-r+1) {
		tate[i]++;
		tate[i+r]--;
	}
	FOR(i,1,n+1) tate[i]+=tate[i-1];
	REP(i,m-r+1) {
		yoko[i]++;
		yoko[i+r]--;
	}
	FOR(i,1,m+1) yoko[i]+=yoko[i-1];
	ll sum=0;
	priority_queue<pair<ll,P>> q;
	tate.resize(n);
	yoko.resize(m);
	sort(ALL(tate));
	sort(ALL(yoko));
	REP(i,n) {
		q.push(pair<ll,P>(tate[i]*yoko[m-1],P(i,m-1)));
	}
	REP(i,k) {
		ll d=q.top().first;
		P p=q.top().second;
		q.pop();
		sum+=d;
		if(p.second-1>=0) {
			q.push(pair<ll,P>(tate[p.first]*yoko[p.second-1],P(p.first,p.second-1)));
		}
	}
	cout<<fixed<<setprecision(39)<<sum/(ld)((n-r+1)*(m-r+1))<<endl;
}