//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2400;
char s[maxn][maxn], d[maxn][maxn];
vector<pair<int, int>> v[26];
struct node{
	int a, b, c, d;
}ans[26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int t;
	for(cin >> t; t; t -= 1){
		int n, m;
		cin >> n >> m;

		for(int i = 0; i < 26; i += 1) v[i].clear();

		for(int i = 1; i <= n; i += 1) cin >> (s[i] + 1);
		
		for(int i = 1; i <= n; i += 1)
			for(int j = 1; j <= m; j += 1){
				d[i][j] = '.';
				if(s[i][j] != '.') v[s[i][j] - 'a'].push_back(make_pair(i, j));
			}

		bool ok = true;

		int h = -1;

		for(int i = 0; i < 26; i += 1)
			if(v[i].size()){
				h = i;
				bool r = true, c = true;
				for(auto p : v[i]) {
					if(p.first != v[i][0].first) r = false;
					if(p.second != v[i][0].second) c = false;
				}

				if(r){
					int minj = m + 1, maxj = 0;
					for(auto p : v[i]){
						minj = min(minj, p.second);
						maxj = max(maxj, p.second);
					}
					ans[i] = {v[i][0].first, minj, v[i][0].first, maxj};
				}
				else if(c){
					int mini = n + 1, maxi = 0;
					for(auto p : v[i]){
						mini = min(mini, p.first);
						maxi = max(maxi, p.first);
					}
					ans[i] = {mini, v[i][0].second, maxi, v[i][0].second};
				}
				else ok = false;
			}
		
		for(int i = h; ~i; i -= 1) if(v[i].empty()) ans[i] = ans[i + 1];
		
		if(ok){
			for(int i = 0; i <= h; i += 1){
				if(ans[i].a == ans[i].c){
					for(int j = ans[i].b; j <= ans[i].d; j += 1) d[ans[i].a][j] = 'a' + i;
				}
				else if(ans[i].b == ans[i].d){
					for(int j = ans[i].a; j <= ans[i].c; j += 1) d[j][ans[i].b] = 'a' + i;
				}
				else assert(0);
			}
		}
		
		for(int i = 1; i <= n; i += 1) for(int j = 1; j <= m; j += 1) if(s[i][j] != d[i][j]) ok = false;

		if(ok){
			cout << "YES\n";
			cout << h + 1 << "\n";
			for(int i = 0; i <= h; i += 1)
				cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << " " << ans[i].d << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}