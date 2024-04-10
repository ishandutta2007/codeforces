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

int main() {_
	int t,n;
	string s;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		string ans = "", ans2 = "";
		int x = n - 1;
		while(x >= 0) {
			if(s[x] == '1') {
				ans += '1';
				x--;
			}
			else break;
		}
		int y = 0;
		while(y < n) {
			if(s[y] == '0') {
				ans2+='0';
				y++;
			} else {
				break;
			}
		}
		for(int i = 1; i < n; ++i) {
			if(s[i-1] == '1' && s[i] == '0') {
				ans2 += '0';
				break;
			}
		}
		cout << ans2 + ans << "\n";
	}
			
	
}