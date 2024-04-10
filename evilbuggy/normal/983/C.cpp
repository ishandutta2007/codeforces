#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, a[N], b[N], cnt[10], pw[10];
map<int, int> mem[N][10];

int dp(int i, int floor, int total, int hash){
	if(i == n + 1 && total == 0)return 0;
	if(mem[i][floor].count(hash)){
		return mem[i][floor][hash];
	}
	int ret = 1e9;
	if(i <= n && total < 4){
		cnt[b[i]]++; total++;
		hash += pw[b[i]];
		ret = min(ret, dp(i + 1, a[i], total, hash) + abs(a[i] - floor) + 1);
		hash -= pw[b[i]];
		cnt[b[i]]--; total--;
	}
	for(int nxt = 1; nxt <= 9; nxt++){
		if(cnt[nxt]){
			int tmp = cnt[nxt];
			hash -= pw[nxt]*cnt[nxt];
			total -= cnt[nxt];
			cnt[nxt] = 0;
			ret = min(ret, dp(i, nxt, total, hash) + abs(floor - nxt) + tmp);
			cnt[nxt] = tmp;
			total += cnt[nxt];
			hash += pw[nxt]*cnt[nxt];
		}
	}
	return mem[i][floor][hash] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	pw[0] = 1;
	for(int i = 1; i < 10; i++){
		pw[i] = pw[i - 1]*5;
	}
	memset(cnt, 0, sizeof(cnt));
	cout << dp(1, 1, 0, 0) << '\n';

	return 0;
}