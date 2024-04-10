//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120;
LL f[maxn][maxn], inf = 1e12;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	LL n, k;
	string s;
	cin >> n >> k >> s;
	f[n][0] = 1;
	for(int i = n - 1; ~i; i -= 1)
		for(int j = 0; j <= n; j += 1)
			if(j == 0) f[i][j] = 1;
			else{
				set<char> sc;
				for(int k = i; k < n; k += 1)
					if(sc.count(s[k])) continue;
					else{
						sc.insert(s[k]);
						f[i][j] += f[k + 1][j - 1];
						f[i][j] = min(f[i][j], inf);
					}
			}
	LL ans = 0;
	for(int i = n; ~i; i -= 1){
		LL h = min(k, f[0][i]);
		ans += h * (n - i);
		k -= h;
	}
	if(k) cout << -1;
	else cout << ans;
	return 0;
}