#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int f[N], g[1 << 3], h[1 << 6][3], cnt[1 << 6];
int p[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(f, 0, sizeof(f));
	for(int n = 1; n < N; n++){
		for(int m = n; m < N; m += n){
			f[m]++;
		}
	}

	memset(h, 0, sizeof(h));
	for(int mask = 0; mask < (1 << 6); mask++){
		cnt[mask] = 0;
		for(int i = 0; i < 6; i++){
			if((mask >> i) & 1){
				for(int j = 0; j < 3; j++){
					h[mask][j] |= (1 << p[i][j]);
				}
				cnt[mask]++;
			}
		}
	}
	
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		g[0] = 0;
		g[1] = f[a];
		g[2] = f[b];
		g[4] = f[c];
		g[3] = f[__gcd(a, b)];
		g[5] = f[__gcd(a, c)];
		g[6] = f[__gcd(b, c)];
		g[7] = f[__gcd(__gcd(a, b), c)];
		int ans = 2*g[7];
		for(int mask = 1; mask < 64; mask++){
			if(cnt[mask]&1){
				ans += g[h[mask][0]]*g[h[mask][1]]*g[h[mask][2]];
				ans += 3*g[h[mask][0]|h[mask][1]]*g[h[mask][2]];
			}else{
				ans -= g[h[mask][0]]*g[h[mask][1]]*g[h[mask][2]];
				ans -= 3*g[h[mask][0]|h[mask][1]]*g[h[mask][2]];
			}
		}
		ans /= 6;
		cout << ans << '\n';
	}

	return 0;
}