#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e6 + 7;
const int MAXV = 2e6 + 7;

int a[MAXN];
int kolvo[MAXV], sum[MAXV];
int counter[MAXV];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		counter[a[i]]++;
	}

	for (int i = 1; i < MAXV; ++i){
		kolvo[i] = kolvo[i - 1] + counter[i];
		sum[i] = sum[i - 1] + counter[i] * i;
	}

	int ans = 1e18 + 7;
	for (int div = 2; div < MAXV; ++div){
		if (div > 2 && !(div % 2)) continue;
		if (div > 3 && !(div % 3)) continue;

		int new_ans = 0;
		
		int l = 0;
		int r = div;
		while (l < r - 1){
			int m = (l + r) / 2;
			if ((div - m) * y < x){
				r = m;
			}
			else{
				l = m;
			}
		}

		int left = 1;
		for (int left = 1; left + div - 1 < MAXV; left += div){
			int right = left + div - 1;
			int last_x = left + l - 1;
			int klv1 = kolvo[last_x] - kolvo[left - 1];
			int klv2 = kolvo[right] - kolvo[last_x];
			new_ans += x * klv1 + y * ((right * klv2) - (sum[right] - sum[last_x]));
		}

		ans = min(ans, new_ans);
	}

	cout << ans << '\n';
	return 0;
}