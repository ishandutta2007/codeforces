#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double PI = 3.14159265358979;
const double E = 2.718281828459045;
const double root2 = sqrt(2);
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	string s;
	int n; cin >> n;
	std::cin >> s;
	bool f = true;
	if (n == 1 && s[0] == '0')f = false;
	if (n == 2) {
		if (s[0] == s[1])f = false;
	}
	if (n > 1 && s[0] == '0'&&s[1] == '0')f = false;
	if (n > 1 && s[n - 1] == '0'&&s[n - 2] == '0')f = false;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '1') {
			if (s[i - 1] == '1' || s[i + 1] == '1') {
				f = false; break;
			}
		}
		else if (s[i] == '0') {
			if (s[i - 1] == '0'&&s[i + 1] == '0') {
				f = false; break;
			}
		}
	}
	if (f)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}