#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;



string s[55];
int n, m, ans = 0;

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < m - 1; j++){
			int k = 0;
			if (s[i][j] == 'f' || s[i][j + 1] == 'f' || s[i + 1][j] == 'f' || s[i + 1][j + 1] == 'f') k++;
			if (s[i][j] == 'a' || s[i][j + 1] == 'a' || s[i + 1][j] == 'a' || s[i + 1][j + 1] == 'a') k++;
			if (s[i][j] == 'c' || s[i][j + 1] == 'c' || s[i + 1][j] == 'c' || s[i + 1][j + 1] == 'c') k++;
			if (s[i][j] == 'e' || s[i][j + 1] == 'e' || s[i + 1][j] == 'e' || s[i + 1][j + 1] == 'e') k++;
			if (k == 4) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}