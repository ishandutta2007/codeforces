#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s;
int ans;
int a1[4] = {1, 2, 4, 3};
int a2[4] = {1, 3, 4, 2};
int a3[2] = {1, 4};


int main() {
	cin >> s;
	if (s.size() == 1 && s[0] == '0') {
		cout << 4 << endl;
		return 0;
	}
	ans = 1;
	ans += a3[(s[s.size() - 1] - '0') % 2];
	int n = s.size() - 1;
	int k = 0;
	for (int i = max(0, n - 1); i <= n; i++) {
		k *= 10;
		k += s[i] - '0';
	}
	ans += a2[k % 4];
	ans += a1[k % 4];
	ans %= 5;
	cout << ans << endl;
	return 0;
}