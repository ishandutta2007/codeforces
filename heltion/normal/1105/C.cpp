#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
#define maxn 240000 
LL f[3][maxn];
int main(){
	int n, l, r;
	cin >> n >> l >> r;
	f[0][1] = r / 3 - (l - 1) / 3;
	f[1][1] = (r + 2) / 3 - (l + 1) / 3;
	f[2][1] = (r + 1) / 3 - l / 3;
	for(int i = 1; i < n; i += 1)
		for(int j = 0; j < 3; j += 1)
			for(int k = 0; k < 3; k += 1){
				f[(j + k) % 3][i + 1] += f[j][i] * f[k][1];
				f[(j + k) % 3][i + 1] %= mod;
			}
	cout << f[0][n];
}