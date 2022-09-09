//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200;
constexpr LL mod = 1000000007;
int a[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int h, w;
	cin >> h >> w;
	for(int i = 1, r; i <= h; i += 1){
		cin >> r;
		for(int j = 1; j <= r; j += 1) a[i][j] = 1;
		a[i][r + 1] = -1;
	}
	for(int i = 1, c; i <= w; i += 1){
		cin >> c;
		for(int j = 1; j <= c; j += 1){
			if(a[j][i] == -1) no(0);
			a[j][i] = 1;
		}
		if(a[c + 1][i] == 1) no(0);
		a[c + 1][i] = -1;
	}
	LL ans = 1;
	for(int i = 1; i <= h; i += 1)
		for(int j = 1; j <= w; j += 1) if(not a[i][j]) ans = ans * 2 % mod;
	cout << ans;
	return 0;
}