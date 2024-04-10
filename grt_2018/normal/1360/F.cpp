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

int t,n,m;
map<string,int>cnt;

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> m;
		cnt.clear();
		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			if(cnt.find(s) == cnt.end()) {
				cnt[s] = 1;
			} else {
				cnt[s] ++;
			}
			for(int j = 0; j < m; ++j) {
				char old = s[j];
				for(int d = 0; d < 26; ++d) {
					if((char)(d + 'a') == old) continue;
					s[j] = (char)(d + 'a');
					if(cnt.find(s) == cnt.end()) {
						cnt[s] = 1;
					} else {
						cnt[s] ++;
					}
				}
				s[j] = old;
			}
		}
		string ans = "-1";
		for(auto it : cnt) {
			if(it.ND == n) ans = it.ST;
		}
		cout << ans << "\n";
	}
}