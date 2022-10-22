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
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int a[MAXN], b[MAXN], pref0[MAXN], pref1[MAXN];
vector <int> v = { -BIG_MOD, BIG_MOD };

void print(int sum){
	int l = 0;
	int r = v.size() - 1;
	while (l < r - 1){
		int mid = (l + r) / 2;
		if (sum + v[mid] <= 0){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	cout << min(abs(v[l] + sum), abs(v[l + 1] + sum)) << '\n';
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	int sum = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if ((i + 1) % 2){
			sum += a[i];
		}
		else{
			sum -= a[i];
		}
	}

	for (int i = 0; i < m; ++i){
		cin >> b[i];
		if ((i + 1) % 2){
			pref0[i + 1] = pref0[i] + b[i];
			pref1[i + 1] = pref1[i];
		}
		else{
			pref0[i + 1] = pref0[i];
			pref1[i + 1] = pref1[i] + b[i];
		}


		if (i >= n - 1){
			int l = i + 1 - n + 1;

			int sum0 = pref0[i + 1] - pref0[l - 1];
			int sum1 = pref1[i + 1] - pref1[l - 1];
			if (l % 2){
				v.push_back(sum1 - sum0);
			}
			else{
				v.push_back(sum0 - sum1);
			}
		}
	}

	sort(v.begin(), v.end());

	print(sum);

	int l, r, x;
	for (int i = 0; i < q; ++i){
		cin >> l >> r >> x;
		int len = r - l + 1;
		if (l % 2){
			sum += x * (len % 2);
		}
		else{
			sum -= x * (len % 2);
		}

		print(sum);
	}

	return 0;
}