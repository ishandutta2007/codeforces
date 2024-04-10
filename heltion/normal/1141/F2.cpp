#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(){cout << -1; exit(0);}
constexpr int maxn = 1600;
LL a[maxn], s[maxn];
map<int, set<pair<int, int> > > mp; 
inline int solve(const set<pair<int, int> > &s){
	int res = 0, r = 0;
	for(const auto &p : s)
		if(p.second >= r){
			res += 1;
			r = p.first;
		}
	return res;
}
inline void out(const set<pair<int, int> > &s){
	int r = 0;
	for(const auto &p : s)
		if(p.second >= r){
			cout << p.second + 1 << " " << p.first << endl;
			r = p.first;
		}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 0; i < n; i += 1)
		for(int j = i + 1; j <= n; j += 1){
			mp[s[j] - s[i]].insert(make_pair(j, i));
		}
	int ans = 0, anss = 0;
	for(const auto &p : mp){
		int res = solve(p.second);
		if(res > ans) ans = res, anss = p.first;
	}
	cout << ans << endl;
	out(mp[anss]);
}