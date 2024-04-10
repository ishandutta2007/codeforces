#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;
const int mod = 998244353;

int inverse[maxN];

void init(){
	inverse[1] = 1;
	for(int i = 2; i < maxN; i++){
		inverse[i] = 1LL*inverse[mod%i]*(mod - mod/i)%mod;
	}
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline int dist2(int x, int y){
	return (1LL*x*x + 1LL*y*y)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int n, m;
	cin >> n >> m;
	vector<array<int, 3> > a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x;
			cin >> x;
			a.push_back({x, i, j});
		}
	}
	sort(a.begin(), a.end());
	vector<vector<int> > ans(n, vector<int>(m));
	int sz = 0, si = 0, sj = 0, sd = 0, se = 0;
	for(int l = 0; l < (int)a.size(); l++){
		int r = l;
		while(r + 1 < (int)a.size() && a[l][0] == a[r + 1][0])r++;

		for(int i = l; i <= r; i++){
			int x = a[i][1];
			int y = a[i][2];
			if(sz == 0){
				ans[x][y] = 0;
			}else{
				long long tmp = sd + se - 2LL*x*si - 2LL*y*sj;
				tmp %= mod; if(tmp < 0)tmp += mod;
				ans[x][y] = (dist2(x, y) + tmp*inverse[sz])%mod;
			}
		}
		for(int i = l; i <= r; i++){
			int x = a[i][1];
			int y = a[i][2];
			add(si, x);
			add(sj, y);
			add(se, ans[x][y]);
			add(sd, dist2(x, y));
		}
		sz += r - l + 1;
		l = r;
	}
	int r, c;
	cin >> r >> c;
	cout << ans[r - 1][c - 1] << '\n';

	return 0;
}