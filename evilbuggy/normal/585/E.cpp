#include <bits/stdc++.h>
using namespace std;

const int N = 10000005;
const int mod = 1000000007;

int g[N], f[N], pw[N], mu[N], lpf[N], cnt[N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		pw[i] = pw[i - 1] << 1;
		if(pw[i] >= mod)pw[i] -= mod;
	}
	memset(lpf, -1, sizeof(lpf));
	for(int i = 2; i*i < N; i++){
		if(lpf[i] == -1){
			for(int m = i*i; m < N; m += i){
				if(lpf[m] == -1){
					lpf[m] = i;
				}
			}
		}
	}
	mu[1] = 1;
	for(int p = 2; p < N; p++){
		if(lpf[p] == -1){
			lpf[p] = p;
			int st = N/p; if(N%p == 0)st--;
			for(int i = st, j = st*p; i >= 1; i--, j -= p){
				cnt[i] += cnt[j];
			}
		}
		int x = p/lpf[p];
		if(x%lpf[p] == 0){
			mu[p] = 0;
		}else{
			mu[p] = -mu[x];
		}
	}
	for(int i = 1; i < N; i++){
		f[i] = pw[cnt[i]] - 1;
		g[i] = mu[i]*cnt[i];
	}
	for(int p = 2; p < N; p++){
		if(lpf[p] == p){
			int en = N/p; if(N%p == 0)en--;
			for(int i = 1, j = p; i <= en; i++, j += p){
				add(f[i], mod - f[j]);
			}
		}
	}
	for(int p = 2; p < N; p++){
		if(lpf[p] == p){
			int en = N/p; if(N%p == 0)en--;
			for(int i = 1, j = p; i <= en; i++, j += p){
				g[j] += g[i];
			}
		}
	}
	int answer = 0;
	for(int i = 2; i < N; i++){
		add(answer, f[i]*1LL*g[i]%mod);
	}
	cout << answer << '\n';

	return 0;
}