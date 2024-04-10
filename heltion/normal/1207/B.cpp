//Author: Heltion
//Date: 08-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 60;
int B[maxn][maxn], A[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1) cin >> A[i][j];
	vector<pair<int, int>> ans;
	for(int i = 1; i < n; i += 1)
		for(int j = 1; j < m; j += 1)
			if(A[i][j] == 1 and A[i + 1][j] == 1 and A[i][j + 1] == 1  and A[i + 1][j + 1] == 1 ){
				B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
				ans.push_back({i, j});
			}
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1)
			if(A[i][j] != B[i][j]) no(-1);
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.first << " " << p.second << "\n";
	return 0;
}