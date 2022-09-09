#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
#define maxn 100
struct mat{
	LL a[maxn][maxn];
	mat operator * (const mat &b){
		mat c;
		memset(c.a, 0, sizeof c.a);
		for(int k = 0; k < maxn; k += 1)
			for(int i = 0; i < maxn; i += 1)
				for(int j = 0; j < maxn; j += 1)
					c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		return c;
	}
};
void no(){
	cout << "1";
	exit(0);
}
mat power(mat a, LL r){
	mat res;
	memset(res.a, 0, sizeof res.a);
	for(int i = 0; i < maxn; i += 1) res.a[i][i] = 1;
	for(; r; r >>= 1, a = a * a)
		if(r & 1) res = res * a;
	return res;
}
mat a;
int main(){
	ios::sync_with_stdio(false);
	LL N, M;
	cin >> N >> M;
	if(N < M) no();
	for(int i = 0; i + 1 < M; i += 1) a.a[i][i + 1] = 1;
	a.a[M - 1][0] = a.a[M - 1][M - 1] = 1;
	mat res = power(a, N - M + 1);
	LL ans = 0;
	for(int i = 0; i < M; i += 1) ans = (ans + res.a[M - 1][i]) % mod;
	cout << ans;
}