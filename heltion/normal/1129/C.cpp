#include<bits/stdc++.h>
#define maxn 3200
using namespace std;
typedef long long LL;
const int mod = 1000000007;
int s[maxn];
int f[maxn][maxn];
int v[maxn];
int C[maxn * maxn][2], cnt = 0;
int test(int i){
	if(i <= 3) return i;
	if(s[i - 3] == 0 and s[i - 2] == 0 and s[i - 1] == 1 and s[i] == 1) return 3;
	if(s[i - 3] == 0 and s[i - 2] == 1 and s[i - 1] == 0 and s[i] == 1) return 3;
	if(s[i - 3] == 1 and s[i - 2] == 1 and s[i - 1] == 1 and s[i] == 0) return 3;
	if(s[i - 3] == 1 and s[i - 2] == 1 and s[i - 1] == 1 and s[i] == 1) return 3;
	return 4;
}
unordered_set<int> us;
void add(int &x, int v){
	x += v;
	if(x >= mod) x -= mod;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1) scanf("%d", s + i);
	for(int i = 1; i <= n; i += 1) v[i] = test(i);
	for(int i = 1; i <= n; i += 1)
		for(int j = i - 1; j <= n; j += 1){
			if(j < i) f[i][j] = 1;
			else for(int k = 1; k <= v[j]; k += 1) add(f[i][j], f[i][j - k]);
			//printf("%d %d %d\n", i, j, f[i][j]);
		}
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		int p = 0;
		for(int j = i; j >= 1; j -= 1){
			if(C[p][s[j]]) p = C[p][s[j]];
			else{
				ans = (ans + f[j][i]) % mod;
				C[p][s[j]] = cnt += 1;
				p = C[p][s[j]]; 
			}
		}
		cout << ans << endl;
	}
}