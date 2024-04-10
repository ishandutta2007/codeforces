#include <bits/stdc++.h>
using namespace std;

const int K = 17;
const int N = 55;
const int M = 105;
const int T = 200005;
const long double PI = acos(-1.0);

int n, m, t, x;
vector<int> g[N];
int a[M], b[M], c[M];
int p[M][T], dist[N][N], suff[M][T];
double dp[N][T], sum[M][T], arr[1 << K];
complex<double> base[1 << K], ibase[1 << K], f[1 << K], h[1 << K];

void init(){
	int B = (1 << K);
	for(int i = 0; i < B; i++){
		base[i] = complex<double>(cos(2*i*PI/B), sin(2*i*PI/B));
		ibase[i] = complex<double>(cos(2*i*PI/B), -sin(2*i*PI/B));
	}
}

inline void fft(complex<double> a[], int nn, bool inv){
	for(int i = 1, j = 0; i < nn; i++){
		int bit = nn >> 1;
		while(j&bit){
			j ^= bit;
			bit >>= 1;
		}
		j ^= bit;
		if(i < j)swap(a[i], a[j]);
	}
	for(int len = 2; len <= nn; len <<= 1){
		int hlen = len >> 1;
		int add = (1 << 17)/len;
		for(int i = 0; i < nn; i += len){
			int cur = 0;
			for(int j = 0; j < hlen; j++){
				complex<double> u = a[i + j];
				complex<double> v = a[i + j + hlen];
				if(inv){
					v *= ibase[cur];
				}else{
					v *= base[cur];
				}
				a[i + j] = u + v;
				a[i + j + hlen] = u - v;
				cur += add;
			}
		}
	}
	if(inv){
		for(int i = 0; i < nn; i++){
			a[i] /= nn;
		}
	}
}

inline void convolve(double a[], int b[], int la, int lb, int len){
	for(int i = 0; i < len; i++){
		f[i] = a[la + i];
		h[i] = b[lb + i];
		f[i + len] = 0.0;
		h[i + len] = 0.0;
	}
	reverse(h, h + len);
	int sz = len << 1;
	fft(f, sz, false);
	fft(h, sz, false);
	for(int i = 0; i < sz; i++){
		f[i] *= h[i];
	}
	fft(f, sz, true);
	for(int i = 0; i < sz; i++){
		arr[i] = f[i].real();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> n >> m >> t >> x;
	memset(dist, 0x3f, sizeof(dist));
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i] >> c[i];
		for(int j = 1; j <= t; j++){
			cin >> p[i][j];
		}
		suff[i][t + 1] = 0;
		for(int j = t; j >= 1; j--){
			suff[i][j] = suff[i][j + 1] + p[i][j];
		}
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
		g[a[i]].emplace_back(i);
	}
	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		dp[i][t + 1] = dist[i][n] + x;
	}
	for(int i = 1; i <= m; i++){
		for(int k = 0; k <= t; k++){
			sum[i][k] = dp[b[i]][t + 1]*suff[i][t - k + 1];
		}
	}
	for(int k = t; k >= 0; k--){
		for(int i = 1; i < n; i++){
			dp[i][k] = 1e18;
			for(int ind : g[i]){
				dp[i][k] = min(dp[i][k], c[ind] + sum[ind][k]/100000);
			}
		}
		dp[n][k] = 0.0;
		int sz = t - k + 1;
		for(int i = 1; i <= m; i++){
			if(k >= 1)sum[i][k - 1] += dp[b[i]][k]*p[i][1];
			if(k >= 2)sum[i][k - 2] += dp[b[i]][k]*p[i][2];
			for(int len = 2; len <= sz; len <<= 1){
				if(sz%len == 0){
					convolve(dp[b[i]], p[i], k, len + 1, len);
					for(int j = 0, st = k - (len << 1); j < (len << 1) && st <= t; j++, st++){
						if(st >= 0){
							sum[i][st] += arr[j];
						}
					}
				}else{
					break;
				}
			}
		}
	}
	cout << fixed << setprecision(20) << dp[1][0] << '\n';

	return 0;
}