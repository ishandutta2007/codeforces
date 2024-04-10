#include <bits/stdc++.h>
using namespace std;

string c, s, t;
vector<int> fs, ft;
int mem[1005][55][55];
int vis[1005][55][55];

int dp(int i, int j, int k){
	if(j == (int)s.size())return dp(i, fs[j - 1], k) + 1;
	if(k == (int)t.size())return dp(i, j, ft[k - 1]) - 1;
	if(i == (int)c.size())return 0;
	if(vis[i][j][k])return mem[i][j][k];
	vis[i][j][k] = 1;
	if(c[i] != '*'){
		int nj = j, nk = k;
		while(nj && s[nj] != c[i])nj = fs[nj - 1];
		while(nk && t[nk] != c[i])nk = ft[nk - 1];
		if(s[nj] == c[i])nj++;
		if(t[nk] == c[i])nk++;
		return mem[i][j][k] = dp(i + 1, nj, nk);
	}
	int ret = -(int)1e9;
	for(char ch = 'a'; ch <= 'z'; ch++){
		int nj = j, nk = k;
		while(nj && s[nj] != ch)nj = fs[nj - 1];
		while(nk && t[nk] != ch)nk = ft[nk - 1];
		if(s[nj] == ch)nj++;
		if(t[nk] == ch)nk++;
		ret = max(ret, dp(i + 1, nj, nk));
	}
	return mem[i][j][k] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> s >> t;
	{
		int i = 1, j = 0;
		int n = (int)s.size();
		fs.resize(n);
		while(i < n){
			if(s[i] == s[j]){
				fs[i] = j + 1;
				++i; ++j;
			}else if(j){
				j = fs[j - 1];
			}else{
				++i;
			}
		}
	}
	{
		int i = 1, j = 0;
		int n = (int)t.size();
		ft.resize(n);
		while(i < n){
			if(t[i] == t[j]){
				ft[i] = j + 1;
				++i; ++j;
			}else if(j){
				j = ft[j - 1];
			}else{
				++i;
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	cout << dp(0, 0, 0) << '\n';

	return 0;
}