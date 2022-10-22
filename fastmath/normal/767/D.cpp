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
const int MAXN = 1e5 + 7;

vector <int> a;
vector <pair <int, int> > b;
int n, m, k;

bool check(int mid){
	vector <int> res;
	int i = 0;
	int j = m - mid;
	for (int it = 0; it < n + mid; ++it){
		if (i == n || (j < m && b[j].first < a[i])) {
			res.push_back(b[j].first);
			++j;
		}
		else{
			res.push_back(a[i]);
			++i;
		}
	}

	for (int i = 0; i < n + mid; ++i){
		int klv = i + 1;
		int day = (klv - 1) / k + 1;
		if (day - 1 > res[i]){
			return false;
		}
	}

	return true;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	a.resize(n);
	b.resize(m);

	for (int i = 0; i < n; ++i){
		scanf("%I64d", &a[i]);
	}

	for (int i = 0; i < m; ++i){
		scanf("%I64d", &b[i].first);
		b[i].second = i;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int l = -1;
	int r = m + 1;
	while (l < r - 1){
		int mid = (l + r) / 2;
		if (check(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	if (l == -1){
		cout << "-1\n";
		return 0;
	}

	cout << l << '\n';
	for (int i = m - l; i < m; ++i){
		cout << b[i].second + 1 << ' ';
	}

	return 0;
}