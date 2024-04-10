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



ll n, l, r, x, ans = 0, a[20];

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (ll i = (1 << n) - 1; i > 0; i--){
		ll sum = 0, cnt = 0, mn = INFll, mx = -INFll;
		for (int j = 0; j < n; j++){
			if ((i >> j) & 1){
				cnt++;
				sum += a[j];
				mn = min(a[j], mn);
				mx = max(a[j], mx);
			}
		}
		if (cnt >= 2 && (mx - mn) >= x && sum >= l && sum <= r) ans++;
	}
	cout << ans << '\n';
}