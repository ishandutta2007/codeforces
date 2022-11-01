#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n, 0);
	REP(i, n) cin>>a[i];
	REP(i, n) cin>>b[i];
	vector<int> dif;
	set<int> s;
	REP(i, n) {
		if(a[i] == b[i]) {
			c[i] = a[i];
			s.insert(c[i]);
		}
		else {
			dif.pb((int)i);
		}
	}
	if(dif.size() == 1) {
		FOR(i, 1, n + 1) {
			if(s.count((int)i) == 0) {
				c[dif[0]] = (int)i;
				break;
			}
		}
		REP(i, n) {
			cout<<c[i];
			if(i != n - 1) cout<<" ";
			else cout<<endl;
		}
	} else {
		if(s.count(a[dif[0]]) == 0 && s.count(b[dif[1]]) == 0 && a[dif[0]] != b[dif[0]]) {
			c[dif[0]] = a[dif[0]];
			c[dif[1]] = b[dif[1]];
		} else {
			c[dif[0]] = b[dif[0]];
			c[dif[1]] = a[dif[1]];
		}
		REP(i, n) {
			cout<<c[i];
			if(i != n - 1) cout<<" ";
			else cout<<endl;
		}
	}
}