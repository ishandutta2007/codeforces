#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};



int main(void) {
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> wa(n);
	ll sum = 0;
	REP(i, n) {
		cin>>a[i];
		sum += a[i];
	}
	REP(i, n) {
		if(i == 0) wa[i] = a[i];
		else {
			wa[i] = wa[i - 1] + a[i];
		}
	}
	if(sum % 2 == 1) {
		cout<<"NO"<<endl;
		return 0;
	}
	sum /= 2;
	vector<ll>::iterator ite;
	ite = lower_bound(ALL(wa), sum);
	if(ite != wa.end() && *ite == sum) {
		cout<<"YES"<<endl;
		return 0;
	}
	bool d = false;
	REP(i, n) {
		ite = lower_bound(ALL(wa), sum - a[i]);
		if(ite != wa.end() && *ite == sum - a[i] && ite - wa.begin() < i) {
			d = true;
			break;
		}
		ite = lower_bound(ALL(wa), sum + a[i]);
		if(ite != wa.end() && *ite == sum + a[i] && ite - wa.begin() > i) {
			d = true;
			break;
		}
	}
	if(d) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}