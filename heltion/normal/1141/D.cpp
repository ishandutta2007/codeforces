#include<bits/stdc++.h>
using namespace std;
void no(){cout << -1; exit(0);}
constexpr int maxn = 150000;
vector<int> v[2][26];
set<int> s[2][2];
vector<pair<int, int> > ans;
char t[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> t;
	for(int i = 0; i < n; i += 1)
		if(t[i] == '?') s[0][0].insert(i);
		else{
			s[0][1].insert(i);
			v[0][t[i] - 'a'].push_back(i);
		}
	cin >> t;
	for(int i = 0; i < n; i += 1)
		if(t[i] == '?') s[1][0].insert(i);
		else{
			s[1][1].insert(i);
			v[1][t[i] - 'a'].push_back(i);
		}
	for(int i = 0; i < 26; i += 1){
		int m = min(v[0][i].size(), v[1][i].size());
		for(int j = 0; j < m; j += 1){
			s[0][1].erase(v[0][i][j]);
			s[1][1].erase(v[1][i][j]);
			ans.push_back(make_pair(v[0][i][j], v[1][i][j]));
		}
	}
	for(auto it = s[0][1].begin(); it != s[0][1].end(); it = s[0][1].erase(it)){
		if(s[1][0].empty()) break;
		ans.push_back(make_pair(*it, *s[1][0].begin()));
		s[1][0].erase(s[1][0].begin());
	}
	for(auto it = s[0][0].begin(); it != s[0][0].end(); it = s[0][0].erase(it)){
		if(s[1][1].empty()) break;
		ans.push_back(make_pair(*it, *s[1][1].begin()));
		s[1][1].erase(s[1][1].begin());
	}
	for(auto it = s[0][0].begin(); it != s[0][0].end(); it = s[0][0].erase(it)){
		if(s[1][0].empty()) break;
		ans.push_back(make_pair(*it, *s[1][0].begin()));
		s[1][0].erase(s[1][0].begin());
	}
	cout << ans.size() << "\n";
	for(auto p : ans)
		cout << p.first + 1 << " " << p.second + 1 << "\n";
}