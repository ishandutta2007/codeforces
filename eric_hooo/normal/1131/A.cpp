#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 2 * (b + 1) + a + 2 * (d + 1) + c + a - c;
	cout << ans << endl;
	return 0;
}