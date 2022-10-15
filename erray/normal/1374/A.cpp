#include<bits/stdc++.h> 

using namespace std;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
  	int x, y, n;
  	cin >> x >> y >> n;
  	int sn = n;
  	n -= n % x;
  	n += y;
  	if (n > sn) n -= x;
  	cout << n << '\n';
  }
}