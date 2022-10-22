#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		int n;
		cin >> n >> s;
		string s2 = s;
		sort(s2.begin(), s2.end());
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] != s2[i]) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}