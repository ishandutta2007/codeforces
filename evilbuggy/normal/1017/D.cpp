#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int M = 105;

int a[N], f[1 << N], w[1 << N], ans[1 << N][M];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(w, 0, sizeof(w));
	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++){
			if(((mask >> i) & 1) == 0)w[mask] += a[i];
		}	
	}
	memset(f, 0, sizeof(f));
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		int val = 0, prd = 1;
		for(auto ch : s){
			if(ch == '1')val ^= prd;
			prd <<= 1;
		}
		f[val]++;
	}
	memset(ans, 0, sizeof(ans));
	for(int mask = 0; mask < (1 << n); mask++){
		for(int dmask = 0; dmask < (1 << n); dmask++){
			if(w[dmask] >= M)continue;
			ans[mask][w[dmask]] += f[mask^dmask];
		}
		for(int i = 1; i < M; i++){
			ans[mask][i] += ans[mask][i - 1];
		}
	}
	while(q--){
		string s;
		cin >> s;
		int val = 0, prd = 1;
		for(auto ch : s){
			if(ch == '1')val ^= prd;
			prd <<= 1;
		}
		int k; cin >> k;
		cout << ans[val][k] << '\n';
	}

	return 0;
}