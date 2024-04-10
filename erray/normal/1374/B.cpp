#include<bits/stdc++.h> 

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
  	long long n;
  	cin >> n;
  	int ans = 0;
  	while (n % 6== 0) {
  		n /= 6;
  		++ans;
  	}
		while (n % 3 == 0) {
  		n /= 3;
  		ans += 2;
  	}
  	if (n == 1) cout << ans;
  	else cout << -1;
  	cout << '\n';
  }
}