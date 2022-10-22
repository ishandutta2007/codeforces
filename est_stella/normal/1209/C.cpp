#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n;
string s;
int c[200010];
vector<int> one;
vector<int> two;

int solve() {
	one.clear();
	two.clear();
	cin >> n;
	cin >> s;

	int f = inf;
	for(int i=0; i<n; i++) {
		while(one.size() && s[one.back()] > s[i]) {
			c[one.back()] = 2;
			f = min(f, one.back());
			one.pop_back();
		}

		if(f < inf && s[f] < s[i]) {
			c[i] = 2;
		}
		else {
			one.pb(i);
			c[i] = 1;
		}
	}

	for(int i=0; i<n; i++) {
		if(c[i] == 2) two.pb(i);
	}

	for(int i=1; i<two.size(); i++) {
		if(s[two[i-1]] > s[two[i]]) {
			cout << "-\n";
			return 0;
		}
	}

	for(int i=0; i<n; i++) {
		cout << c[i];
	} 
	cout << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}