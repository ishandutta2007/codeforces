#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main() {
	int n, i, j,k;
	cin >> n;
	string s;
	int sum; sum = 0;
	int csum[4] = {};
	for (i = 0; i < 4; i++) {
		for (j = 0; j < n; j++) {
			cin >> s;
			for (k = 0; k < n; k++) {
				if ((j + k) % 2 == 0&&s[k]!='1') {
					csum[i]++;
				}
				else if ((j + k) % 2 == 1 && s[k] == '1') {
					csum[i]++;
				}
			}
		}
	}
	std::sort(csum, csum + 4);
	std::cout << csum[0] + csum[1] + n * n - csum[2] + n * n - csum[3] << endl;
	return 0;
}