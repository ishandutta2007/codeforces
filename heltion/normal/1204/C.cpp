//Author: Heltion
//Date: 08-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120;
constexpr int maxm = 1200000;
constexpr int inf = 1200;
char s[maxn][maxn];
int d[maxn][maxn];
int p[maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> (s[i] + 1);
		for(int j = 1; j <= n; j += 1)
			if(s[i][j] == '0') d[i][j] = i == j ? 0 : inf;
			else d[i][j] = 1;
	}
	for(int k = 1; k <= n; k += 1)
		for(int i = 1; i <= n; i += 1)
			for(int j = 1; j <= n; j += 1)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	vector<int> ans;
	int m;
	cin >> m;
	for(int i = 1; i <= m; i += 1) cin >> p[i];
	for(int i = 1, j, s; i <= m; i = j){
		ans.push_back(p[i]);
		for(s = 0, j = i; j <= m; j += 1){
			if(s + d[p[j]][p[j + 1]] != d[p[i]][p[j + 1]]) break;
			s += d[p[j]][p[j + 1]];
		}
	}
	cout << ans.size() << "\n";
	for(int x : ans) cout << x << " ";
	return 0;
}