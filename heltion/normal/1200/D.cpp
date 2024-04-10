//Author: Heltion
//Date: 08-12-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 2400;
char s[maxn][maxn];
int ans[maxn][maxn];
void add(int r1, int c1, int r2, int c2){
	ans[r1][c1] += 1;
	ans[r1][c2 + 1] -= 1;
	ans[r2 + 1][c1] -= 1;
	ans[r2 + 1][c2 + 1] += 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
	for(int i = 1; i <= n; i += 1){
		int L = -1, R = -1;
		for(int j = 1; j <= n; j += 1) if(s[i][j] == 'B'){
			if(!~L) L = j;
			R = j;
		}
		if(~L){
			if(R - L + 1 <= k) add(max(1, i - k + 1), max(1, R - k + 1), i, L);
		}
		else add(1, 1, n, n);
	}
	for(int i = 1; i <= n; i += 1){
		int L = -1, R = -1;
		for(int j = 1; j <= n; j += 1) if(s[j][i] == 'B'){
			if(!~L) L = j;
			R = j;
		}
		if(~L){
			if(R - L + 1 <= k) add(max(1, R - k + 1), max(1, i - k + 1), L, i);
		}
		else add(1, 1, n, n);
	}
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1) ans[i][j] += ans[i][j - 1];
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1) ans[i][j] += ans[i - 1][j];
	int x = 0;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1) x = max(ans[i][j], x);
	cout << x;
	return 0;
}