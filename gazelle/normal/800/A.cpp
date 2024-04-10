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
	ll n,p;
	cin>>n>>p;
	vector<ll> a(n);
	vector<ll> b(n);
	REP(i,n) cin>>a[i]>>b[i];
	ll sumC=0,sumD=0;
	REP(i,n) sumC+=a[i];
	REP(i,n) sumD+=b[i];
	if(sumC<=p) {
		cout<<-1<<endl;
		return 0;
	}
	ld lb=0,ub=INF*INF;
	REP(roop,100) {
		ld mid=(lb+ub)/2;
		ld cost=0;
		REP(i,n) {
			cost+=max((ld)0,mid*a[i]-b[i]);
		}
		if(cost>p*mid) ub=mid;
		else lb=mid;
	}
	cout<<fixed<<setprecision(39)<<lb<<endl;
}