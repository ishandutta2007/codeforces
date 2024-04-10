//Author: Heltion
//Date: 08-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = int;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 700;
constexpr int maxnn = 500000 + 1;
LL B[maxn][maxn];
LL A[maxnn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		LL t, x, y;
		cin >> t >> x >> y;
		if(t == 1){
			A[x] += y;
			for(int i = 1; i < maxn; i ++) B[i][x % i] += y;
		}
		else{
			if(x >= maxn){
				LL ans = 0;
				for(int i = y; i <= maxnn; i += x) ans += A[i];
				cout << ans << "\n";
			}
			else cout << B[x][y] << "\n";
		}
	}
	return 0;
}