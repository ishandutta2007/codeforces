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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
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
	ll n,r,k;
	cin>>n>>r>>k;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	ll lb=INF*INF*2ll,ub=INF*INF*2ll;
	vector<ll> b(n,0);
	queue<ll> _q;
	ll _sum=0;
	REP(i,n) {
		b[i]+=_sum;
		_sum+=a[i];
		_q.push(a[i]);
		if((ll)_q.size()>r) {
			_sum-=_q.front();
			_q.pop();
		}
	}
	while((ll)_q.size()>0) _q.pop();
	_sum=0;
	for(ll i=n-1; i>=0; i--) {
		b[i]+=_sum;
		_sum+=a[i];
		_q.push(a[i]);
		if((ll)_q.size()>r) {
			_sum-=_q.front();
			_q.pop();
		}
	}
	REP(i,n) a[i]+=b[i];
	REP(i,n) lb=min(lb,a[i]);
	while(ub-lb>1) {
		ll mid=(lb+ub)/2;
		ll sum=0;
		ll paff=0;
		queue<ll> q;
		REP(i,n) {
			sum+=max(0ll,mid-(a[i]+paff));
			q.push(max(0ll,mid-(a[i]+paff)));
			paff+=max(0ll,mid-(a[i]+paff));
			if((ll)q.size()>2*r) {
				paff-=q.front();
				q.pop();
			}
			if(sum>k) break;
		}
		if(sum<=k) lb=mid;
		else ub=mid;
	}
	cout<<lb<<endl;
}