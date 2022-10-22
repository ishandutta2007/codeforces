#include <bits/stdc++.h>
using namespace std;

int a[200010];
int dp[5010];
int pd[200010];
int path[5010];

long long power(int a, int b, int mod){
	if (!b) return 1;
	long long t = power(a, b >> 1, mod);
	return b & 1 ? t * t % mod * a % mod : t * t % mod;
}

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int m, phi;

int get(int a, int b){
	int g = gcd(a, b);
	a /= g, b /= g;
	return 1ll * b * power(a, phi - 1, m) % m;
}

int main(){
	int n;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		if (gcd(i, m) == 1) phi++;
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		pd[a[i]] = 1;
	}
	sort(a, a + n);
	vector <int> factor;
	for (int i = 1; i * i <= m; i++){
		if (m % i != 0) continue;
		factor.push_back(i), factor.push_back(m / i);
		if (i * i == m) factor.pop_back();
	}
	sort(factor.begin(), factor.end());
	reverse(factor.begin(), factor.end());
	dp[0] = pd[0] == 0;
	int pos = 0;
	for (int i = 1; i < factor.size(); i++){
		int p = factor[i], maxj = -1;
		for (int j = 0; j < i; j++){
			if (factor[j] % p == 0){
				if (maxj < dp[j]) maxj = dp[j], path[i] = j;
			}
		}
		int cnt = 0;
		for (int j = 0; j < m; j += p){
			cnt += pd[j] || gcd(j, m) != p;
		}
		dp[i] = maxj + m / p - cnt;
		if (dp[pos] < dp[i]) pos = i;
	}
//	cout << "  " << dp[0] << " " << dp[1] << endl;
	printf("%d\n", dp[pos]);
	vector <int> res;
	int flag = 1;
	while (pos != 0 || flag){
		if (pos == 0) flag = 0;
		int p = factor[pos];
//		cout << "         p:" << p << endl;
		for (int i = 0; i < m; i += p){
//			cout << "          i:" << i << endl;
			if (!pd[i] && gcd(i, m) == p) res.push_back(i);
		}
		pos = path[pos];
	}
//	cout << "res:";
//	for (int i = 0; i < res.size(); i++){
//		cout << res[i] << " ";
//	}
//	cout << endl;
	vector <int> ans;
	ans.push_back(res[0]);
//	cout << "          phi:" << phi << endl;
	for (int i = 1; i < res.size(); i++){
		int tmp = gcd(res[i - 1], res[i]);
		ans.push_back(get(res[i - 1], res[i]));
	}
//	cout << "                     " << get(6, 4) << endl;
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	} 
	printf("\n");
	return 0;
}