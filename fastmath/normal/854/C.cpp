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
const int MAXN = 3e5 + 7;

bool comp(pair <int, int> a, pair <int, int> b){
	return a.first > b.first;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%I64d%I64d", &n, &k);
	vector <pair <int, int> > cost(n);
	for (int i = 0; i < n; ++i){
		scanf("%I64d", &cost[i].first);
		cost[i].second = i + 1;
	}

	sort(cost.begin(), cost.end(), comp);
	int ans = 0;
	vector <int> pos(n);
	set <int> s;
	for (int i = k + 1; i <= k + n; ++i) s.insert(i);
	for (int i = 0; i < n; ++i){
		int p = *s.lower_bound(cost[i].second);
		pos[cost[i].second - 1] = p;
		ans += (p - cost[i].second) * cost[i].first;
		s.erase(p);
	}

	cout << ans << '\n';
	for (int i = 0; i < n; ++i) cout << pos[i] << ' ';
	return 0;
}