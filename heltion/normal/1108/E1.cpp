#include<bits/stdc++.h>
using namespace std;
#define maxn 120000
#define maxm 400
int f[17][maxn];
int LN[maxn];
pair<int, int> v[maxm];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) cin >> f[0][i];
	for(int i = 1; i <= m; i += 1) cin >> v[i].first >> v[i].second;
	for(int i = 1; i < 17; i += 1) LN[1 << i] = i;
	for(int i = 1; i <= maxn; i += 1) if(LN[i] == 0) LN[i] = LN[i - 1];
	for(int i = 1, EX = 2; i < 17; i += 1, EX *= 2)
		for(int j = 1; j + EX - 1 <= n; j += 1)
			f[i][j] = min(f[i - 1][j], f[i - 1][j + (EX / 2)]);
	int ans = 0, mi = 0;
	for(int i = 1; i <= n; i += 1){
		map<int, int> mm;
		for(int j = 1; j <= m; j += 1) if(v[j].first > i || v[j].second < i){
			mm[v[j].first] -= 1;
			mm[v[j].second + 1] += 1;
		}
		mm[n + 1] += 0;
		int L = 1, R, add = 0;
		for(auto p : mm){
			R = p.first;
			if(R == 1){
				add += p.second;
				continue;
			}
			int ln = LN[R - L];
			int x = min(f[ln][L], f[ln][R - (1 << ln)]);
			//cout << i << " " << L << " " << R << " " << x << endl;
			//cout << add << endl;
			if(f[0][i] - x - add > ans){
				ans = f[0][i] - x - add;
				mi = i;
			}
			add += p.second;
			L = R;
		}
	}
	cout << ans << endl;
	int c = 0;
	for(int j = 1; j <= m; j += 1) if(v[j].first > mi || v[j].second < mi){
		c += 1;
	}
	cout << c << endl;
	for(int j = 1; j <= m; j += 1) if(v[j].first > mi || v[j].second < mi){
		cout << j << " ";
	}
}