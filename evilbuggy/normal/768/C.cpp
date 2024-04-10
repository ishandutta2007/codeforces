#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int cnt[2][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, x;
	cin >> n >> k >> x;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		int y;
		cin >> y;
		cnt[0][y]++;
	}
	int flg = 0;
	for(int it = 0; it < k; it++){
		int nflg = flg^1;
		memset(cnt[nflg], 0, sizeof(cnt[nflg]));
		for(int i = 0, cur = 0; i < N; i++){
			if(cnt[flg][i]&1){
				if(cur&1){
					cnt[nflg][i] += (cnt[flg][i] + 1) >> 1;
					cnt[nflg][i^x] += (cnt[flg][i] - 1) >> 1;
				}else{
					cnt[nflg][i] += (cnt[flg][i] - 1) >> 1;
					cnt[nflg][i^x] += (cnt[flg][i] + 1) >> 1;
				}
				cur ^= 1;
			}else{
				cnt[nflg][i] += cnt[flg][i] >> 1;
				cnt[nflg][i^x] += cnt[flg][i] >> 1;
			}
		}
		flg = nflg;
	}
	int mn = N, mx = 0;
	for(int i = 0; i < N; i++){
		if(cnt[flg][i]){
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}
	cout << mx << " " << mn << '\n';

	return 0;
}