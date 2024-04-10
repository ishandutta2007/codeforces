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
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;
typedef vector<P> vp;
typedef vector<vector<P> > vpp;

int main() {
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	vector<ll> c(n);
	REP(i,n) cin>>c[i];
	priority_queue<P> fl;
	vector<ll> res(n);
	REP(i,k) {
		fl.push(P(c[i],i));
	}
	REP(i,n) {
		if(k+i<n) {
			fl.push(P(c[k+i],k+i));
		}
		P p=fl.top();
		fl.pop();
		res[p.second]=k+1+i;
	}
	ll sum=0;
	REP(i,n) {
		sum+=(res[i]-i-1)*c[i];
	}
	cout<<sum<<endl;
	REP(i,n) {
		cout<<res[i];
		if(i!=n-1) cout<<" ";
		else cout<<endl;
	}
}