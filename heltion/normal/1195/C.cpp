//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
void no(){cout << "NO"; exit(0);}
LL h[2][maxn];
LL f[3][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> h[0][i];
	for(int i = 1; i <= n; i += 1) cin >> h[1][i];
	for(int i = 1; i <= n; i += 1){
		f[0][i] = h[0][i] + max(f[1][i - 1], f[2][i - 1]);
		f[1][i] = h[1][i] + max(f[0][i - 1], f[2][i - 1]);
		f[2][i] = max(max(f[0][i - 1], f[1][i - 1]), f[2][i - 1]);
		//cout << i << " " << f[0][i] << " " << f[1][i] << " " << f[2][i] << "\n";
	}
	cout << max(max(f[0][n], f[1][n]), f[2][n]);
	return 0;
}