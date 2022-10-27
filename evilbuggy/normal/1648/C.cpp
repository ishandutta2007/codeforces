#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 200*1000 + 5;

int cnt[maxn], f[maxn], t[maxn];
int fac[maxn], ifac[maxn], inv[maxn];

void init(){
	fac[0] = ifac[0] = 1;
	fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2; i < maxn; i++){
		fac[i] = 1LL*i*fac[i - 1]%mod;
		inv[i] = 1LL*(mod - mod/i)*inv[mod%i]%mod;
		ifac[i] = 1LL*inv[i]*ifac[i - 1]%mod;
	}
}

inline void update(int i, int x){
	while(i < maxn){
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i){
	int ret = 0;
	while(i){
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int n; cin >> n;
	int m; cin >> m;
	memset(f, 0, sizeof(f));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		update(x, 1); cnt[x]++;
	}
	for(int j = 1; j <= m; j++){
		cin >> t[j];
	}
	int tot = fac[n];
	for(int i = 1; i < maxn; i++){
		tot = 1LL*tot*ifac[cnt[i]]%mod;
	}
	int ans = 0;
	int cur = 1;
	for(int i = 1; i <= m; i++){
		add(ans, cur*(1LL*query(t[i] - 1)*inv[n - i + 1]%mod)%mod);
		if(cnt[t[i]] == 0)break;

		cur = cur*(1LL*cnt[t[i]]*inv[n - i + 1]%mod)%mod;
		update(t[i], -1); cnt[t[i]]--;
	}
	ans = 1LL*ans*tot%mod;
	bool flg = true;
	for(int i = 1; i < maxn; i++){
		if(cnt[i]){
			flg = false;
			break;
		}
	}
	if(flg && n < m){
		ans = (ans + 1)%mod;
	}
	cout << ans << '\n';

	return 0;
}