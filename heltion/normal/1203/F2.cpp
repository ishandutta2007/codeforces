//Author: Heltion
//Date: 08-13-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120;
constexpr int maxm = 700000;
struct node{
	int a, b;
}z[maxn], f[maxn];
int dp[2][maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, r, zn = 0, fn = 0, ans = 0;
	cin >> n >> r;
	for(int i = 0; i < n; i += 1){
		int a, b;
		cin >> a >> b;
		if(b >= 0) z[zn ++] = {a, b};
		else f[fn += 1] = {a, b};
	}
	sort(z, z + zn, [](const node &x, const node &y){
		return x.a < y.a;
	});
	for(int i = 0; i < zn; i += 1) if(r >= z[i].a) r += z[i].b, ans += 1;
	sort(f + 1, f + fn + 1, [](const node &x, const node &y){
		return x.a + x.b > y.a + y.b;
	});
	if(fn == 0) no(ans);
	fill(dp[0], dp[0] + maxm, -n);
	dp[0][r] = ans;
	for(int i = 1; i <= fn; i += 1){
		int v = i & 1, u = v ^ 1;
		fill(dp[v], dp[v] + maxm, -n);
		for(int j = 0; j < maxm; j += 1){
			dp[v][j] = max(dp[v][j], dp[u][j]);
			if(j >= f[i].a and j + f[i].b >= 0) dp[v][j + f[i].b] = max(dp[v][j + f[i].b], dp[u][j] + 1);
		}
	}
	cout << *max_element(dp[fn & 1], dp[fn & 1] + maxm);
	return 0;
}