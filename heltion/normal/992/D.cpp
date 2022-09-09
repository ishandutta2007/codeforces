#include<bits/stdc++.h> 
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL a[maxn], k;
int nxt[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	nxt[n + 1] = n + 1;
	a[n + 1] = 10111213;
	for(int i = n; i >= 1; i -= 1) if(a[i] > 1) nxt[i] = i;
	else nxt[i] = nxt[i + 1];
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		LL p = 1, s = 0;
		for(int j = i; ; j = nxt[j] + 1){
			if(p % k == 0 and p / k - s >= 0 and p / k - s <= nxt[j] - j) ans += 1;
			if(j > n) break;
			if(p >= 3e18 / a[nxt[j]]) break;
			p *= a[nxt[j]];
			s += a[nxt[j]] + nxt[j] - j;
		};
	}
	cout << ans;
	return 0;
}