#include<bits/stdc++.h> 
using namespace std;
constexpr int maxn = 1200;
char s[maxn][maxn];
int down[maxn][maxn];
int cnt[maxn][maxn]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
	for(int i = n; i; i -= 1) for(int j = m; j; j -= 1){
		if(s[i][j] != s[i + 1][j]) down[i][j] = 1;
		else down[i][j] = down[i + 1][j] + 1;
	}
	int ans = 0;
	for(int i = n; i; i -= 1) for(int j = m; j; j -= 1){
		int x = i + down[i][j], y = x + down[x][j];
		if(y > n) continue;
		if(down[i][j] != down[x][j] or down[x][j] > down[y][j]) continue;
		cnt[i][j] = 1; 
		int a = i + down[i][j + 1], b = a + down[a][j + 1];
		if(b > n) continue;
		if(x != a or b != y or down[b][j + 1] < down[i][j]) continue;
		if(s[i][j] != s[i][j + 1] or s[x][j] != s[a][j + 1] or s[y][j] != s[b][j + 1]) continue; 
		cnt[i][j] += cnt[i][j + 1];
	}
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1) ans += cnt[i][j];
	cout << ans;
	return 0;
}