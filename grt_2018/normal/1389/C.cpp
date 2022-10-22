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

const int nax = 200 * 1000 + 10;
int t;
string s;

int main() {_
	cin >> t;
	while(t--) {
		cin >> s;
		int ans = 0;
		for(int i = 0; i < 10; ++i) {
			int cnt = 0;
			for(char c : s) {
				if(c - '0' == i) {
					cnt ++;
				}
			}
			ans = max(ans, cnt);
		}
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 10; ++j) {
				int a = i, b = j;
				int cnt = 0;
				for(char c : s) {
					if(c - '0' == a) {
						cnt++;
						swap(a,b);
					}
				}
				if(cnt % 2 == 1) cnt--;
				ans = max(ans, cnt);
			}
		}
		cout << (int)s.size() - ans << "\n";
	}
				
	
}