#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

int vis[1000010];

int main(){
	srand(3232323);
	int n, cnt = 60;
	scanf("%d", &n);
	int d = 0;
	vector <int> v;
	int maxj = 0;
	int last = log(1000000001) / log(2) + 1;
	int tot = 0;
	int minj = 2e9;
	while (cnt > last){
		int x = 1ll * rand() * rand() % n + 1;
		if (tot == n) break;
		if (vis[x]) continue;
		vis[x] = 1, tot++;
		printf("? %d\n", x), fflush(stdout);
		int val; scanf("%d", &val);
		v.push_back(val);
		minj = min(minj, val);
		maxj = max(maxj, val);
		cnt--;
		last = log(1000000000 - maxj + 1) / log(2) + 1;
	}
	int l = maxj, r = 1000000000;
	while (l < r){
		int mid = l + r >> 1;
		printf("> %d\n", mid), fflush(stdout);
		int pd; scanf("%d", &pd);
		if (pd) l = mid + 1;
		else r = mid;
		cnt--;
	}
	int max_num = l;
	v.push_back(max_num);
	while (cnt--){
		int x = 1ll * rand() * rand() % n + 1;
		if (tot == n) break;
		if (vis[x]) continue;
		vis[x] = 1, tot++;
		printf("? %d\n", x), fflush(stdout);
		int val; scanf("%d", &val);
		v.push_back(val);
		minj = min(minj, val);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++){
		d = gcd(d, v[i] - v[i - 1]);
	}
	vector <int> factor;
	for (int i = 1; i * i <= d; i++){
		if (d % i != 0) continue;
		factor.push_back(i);
		factor.push_back(d / i);
		if (i * i == d) break;
	}
	sort(factor.begin(), factor.end()), reverse(factor.begin(), factor.end());
	for (int i = 0; i < factor.size(); i++){
		d = factor[i];
		if (max_num - 1ll * (n - 1) * d > minj || max_num - 1ll * (n - 1) * d < 0) continue;
		printf("! %d %d\n", max_num - (n - 1) * d, d), fflush(stdout);
		return 0;
	}
	return 0;
}