#include<bits/stdc++.h> 

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
  	int n;
  	string s;
  	cin >> n >> s;
  	int ans = 0;
  	for (int i = 0, sum = 0; i < n; ++i, sum = max(0, sum)) {
  		sum += (s[i] == '(' ? 1 : -1);
  		ans += sum < 0;
  	}
  	cout << ans << '\n';
  }
}