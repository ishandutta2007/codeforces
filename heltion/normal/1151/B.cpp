#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 600;
constexpr int maxa = 1 << 10;
int a[maxn][maxn], c[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m, s = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1){
		for(int j = 1; j <= m; j += 1) cin >> a[i][j];
		s ^= a[i][1];
	}
	if(s){
		cout << "TAK\n";
		for(int i = 1; i <= n; i += 1) cout << "1 ";
		return 0;
	}
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1)
			if(a[i][j] != a[i][1]){
				cout << "TAK\n";
				for(int k = 1; k <= n; k += 1) cout << (k == i ? j : 1) << " ";
				return 0;
			}
	cout << "NIE";
}