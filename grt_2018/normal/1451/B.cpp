#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 110;
int t, n, q;
string s;
int cnt1[nax], cnt0[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> q >> s;
		for(int i = 1; i <= n; ++i) {
			cnt1[i] = cnt1[i - 1] + (s[i - 1] == '1');
			cnt0[i] = i - cnt1[i];
		}
		while(q--) {
			int a, b;
			cin >> a >> b;
			bool ok = 0;
			if(s[a - 1] == '1') {
				ok |= (cnt1[a - 1] > 0);
			} else {
				ok |= (cnt0[a - 1] > 0);
			}
			if(s[b - 1] == '1') {
				ok |= (cnt1[n] != cnt1[b]);
			} else {
				ok |= (cnt0[n] != cnt0[b]);
			}
			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
}