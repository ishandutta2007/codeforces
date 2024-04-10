#include<iostream>
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
	int n, m; std::cin >> n >> m;
	char land[102][102];
	for (int i = 0; i <=n+1; i++) {
		land[i][0] = '.';
		land[i][m+1] = '.';
	}
	for (int i = 0; i <= m+1; i++) {
		land[0][i] = '.';
		land[n + 1][i] = '.';
	}
	string s;
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		for (int j = 1; j <= m; j++) {
			land[i][j] = s[j-1];
		}
	}
	bool f = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (land[i][j]!='*') {
				int a=land[i][j]-'0';
				if (land[i][j] == '.')a = 0;
				int count = 0;
				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if (land[k][l] == '*')count++;
					}
				}
				if (count != a)f = false;
			}
		}
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}