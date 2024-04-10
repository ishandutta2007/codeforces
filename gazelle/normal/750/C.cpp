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
	ll lb=0,ub=0;
	bool det=true;
	REP(i,n) {
		ll c,d;
		cin>>c>>d;
		if(i==0) {
			if(d==1) {
				lb=1900;
				ub=INF*INF;
			} else {
				lb=-INF*INF;
				ub=1899;
			}
		}
		if((d==1&&ub<1900)||(d==2&&lb>=1900)) det=false;
		if(d==1) {
			lb=max(lb,1900ll);
		} else {
			ub=min(ub,1899ll);
		}
		lb+=c;
		ub+=c;
	}
	if(det) {
		if(ub>INF) cout<<"Infinity"<<endl;
		else cout<<ub<<endl;
	} else {
		cout<<"Impossible"<<endl;
	}
}