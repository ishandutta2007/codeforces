#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;

int B[maxn + 1], cnt[maxn];
map<pair<int, int>, int> mem;

inline int ncr(int n, int r){
	if(r < 0 || r > n)return 0;
	return ((n&r) == r);
}

inline int count(int l, int r, int n, int k){
	if(l == 1){
		if(r == n){
			n = 0;
		}else{
			n = n - r - 1;
			k = k - 1;
		}
	}else{
		if(r == n){
			n = l - 2;
			k = k - 1;
		}else{
			n = n + l - r - 3;
			k = k - 2;
		}
	}
	k = max(k, 0);
	if(mem.count({n, k}))return mem[{n, k}];
	
	int ret = 0;
	for(int i = k; i <= n; i++){
		ret ^= ncr(n, i);
	}
	return mem[{n, k}] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	for(int i = 1; i <= n; i++){
		cin >> B[i];
	}
	memset(cnt, 0, sizeof(cnt));
	for(int l = 1; l <= n; l++){
		long long cur = B[l];
		cnt[cur] ^= count(l, l, n, k);
		for(int r = l + 1; r <= n; r++){
			if(B[r] >= 20)break;
			cur <<= B[r];
			if(cur >= maxn)break;
			cnt[cur] ^= count(l, r, n, k);
		}
	}
	string ans = "";
	for(int i = 0; i < maxn; i++){
		ans += char('0' + cnt[i]);
	}
	while(ans.size() > 1 && ans.back() == '0')ans.pop_back();
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}