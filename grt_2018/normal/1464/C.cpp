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

string s;
int n;
ll t;
int cnt[63];

int main() {_
	cin >> n >> t >> s;
	for(int i = 0; i < n; ++i) {
		if(i < n - 1) {
			t += (1 << (s[i] - 'a'));
			if(i < n - 2) {
				cnt[s[i] - 'a' + 1]++;
			}
		} else {
			t -= (1 << (s[i] - 'a'));
		}
	}
	//~ cout << t << "\n";
	bool ok = 1;
	for(int i = 0; i < 60; ++i) {
		if(t & (1LL << i)) {
			if(cnt[i] == 0) ok = 0;
			else {
				cnt[i]--;
			}
			cnt[i + 1] += cnt[i] / 2;
		} else {
			cnt[i + 1] += cnt[i] / 2;
		}
	}
	if(ok) cout << "Yes";
	else cout << "No";
	
	
}