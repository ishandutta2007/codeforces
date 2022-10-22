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

int t, n, k;
string s, w;
int cnt1[30], cnt2[30];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n >> k >> s >> w;
		for(int i = 0; i < 26; ++i) cnt1[i] = cnt2[i] = 0;
		for(auto x : s) {
			cnt1[x - 'a']++;
		}
		for(auto x : w) {
			cnt2[x - 'a']++;
		}
		bool ok = 1;
		for(int i = 0; i < 26; ++i) {
			if(cnt1[i] < cnt2[i]) {
				ok = 0;
				break;
			}
			cnt1[i] -= cnt2[i];
			if(cnt1[i] % k != 0) {
				ok = 0;
				break;
			}
			cnt1[i + 1] += cnt1[i];
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
			
		
	
}