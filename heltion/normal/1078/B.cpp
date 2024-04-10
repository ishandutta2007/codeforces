#include<bits/stdc++.h>
#define maxn 120
using namespace std;
typedef long long LL;
int a[maxn];
LL f[2][maxn][maxn * maxn];
LL C[maxn][maxn];
map<int, int> mp;
int main(){
	for(int i = 0; i < maxn; i += 1)
		for(int j = 0; j <= i; j += 1){
			if(j == 0) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		mp[a[i]] += 1;
	}
	f[0][0][0] = 1;
	for(int i = 1, u = 1; i <= n; i += 1, u ^= 1){
		memset(f[u], 0, sizeof f[u]); 
		for(int j = 0; j <= i; j += 1)
			for(int k = 0; k < maxn * maxn; k += 1){
				f[u][j][k] += f[u ^ 1][j][k];
				if(j and k >= a[i]) f[u][j][k] += f[u ^ 1][j - 1][k - a[i]];
			}
		//for(int j = 0; j <= i; j += 1)
			//for(int k = 0; k < 10; k += 1)
				//cout << i << " " << j << " " << k << " " << f[u][j][k] << endl;
		}
	int ans = 0;
	for(auto p : mp){
		int a = p.first, c = p.second;
		for(int i = 1; i <= c; i += 1){
			if(f[n & 1][i][i * a] == C[c][i]) ans = max(ans, i);
			if(f[n & 1][i][i * a] == C[c][i] and i == c and mp.size() == 2) ans = n;
		}
	}
	cout << ans;
}