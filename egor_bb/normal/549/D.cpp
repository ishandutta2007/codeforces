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



string s[105];
ll cnt[105][105], n, m, ans;

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = n - 1; i >= 0; i--){
		for (int j = m - 1; j >= 0; j--){
			if (s[i][j] == 'B' && cnt[i][j] != -1){
				for (int q = 0; q <= i; q++){
					for (int w = 0; w <= j; w++){
						cnt[q][w] += -1 - cnt[i][j];
					}
				}
				ans++;
			} else if (s[i][j] == 'W' && cnt[i][j] != 1){
				for (int q = 0; q <= i; q++){
					for (int w = 0; w <= j; w++){
						cnt[q][w] += 1 - cnt[i][j];
					}
				}
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}