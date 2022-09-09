#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
int s[maxn], t[maxn], d[maxn];
int w[maxn];
vector<int> z[maxn], f[maxn];
int nxt[maxn], nxw[maxn];
multiset<pair<int, int>, greater<pair<int, int> > > se;
LL ans[maxn][201];
int n;
/*
LL ans(int i, int j){
	if(mp.count(make_pair(i, j))) return mp[make_pair(i, j)];
	if(i > n) return mp[make_pair(i, j)] = 0;
	if(j == 0) return mp[make_pair(i, j)] = ans(nxt[i], 0) + nxw[i];
	LL ans1 = ans(nxt[i], j) + nxw[i], ans2 = ans(i + 1, j - 1);
	if(ans1 < ans2) return mp[make_pair(i, j)] = ans1;
	return mp[make_pair(i, j)] = ans2;
}
*/
int main(){
	ios::sync_with_stdio(false);
	//cout << (sizeof(ans) >> 20) << endl;
	int m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i += 1){
		cin >> s[i] >> t[i] >> d[i] >> w[i];
		z[s[i]].push_back(i);
		f[t[i]].push_back(i);
	}
	for(int i = 1; i <= n; i += 1){
		for(int j : z[i]) se.insert(make_pair(w[j], d[j]));
		if(se.empty()) nxt[i] = i + 1, nxw[i] = 0;
		else nxt[i] = se.begin()->second + 1, nxw[i] = se.begin()->first;
		for(int j : f[i]) se.erase(se.find(make_pair(w[j], d[j])));
	}
	for(int i = n; i >= 1; i -= 1)
		for(int j = m; j >= 0; j -= 1){
			//cout << i << j << endl;
			if(j == 0) ans[i][j] = ans[nxt[i]][0] + nxw[i];
			//cout << i << j << endl;
			if(j != 0){
				LL ans1 = ans[nxt[i]][j] + nxw[i], ans2 = ans[i + 1][j - 1];
				ans[i][j] = min(ans1, ans2);
			}
			//cout << i << j << endl;
		}
	cout << ans[1][m];
}