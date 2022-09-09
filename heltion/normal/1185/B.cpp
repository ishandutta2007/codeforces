//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n;
	for(cin >> n; n; n -= 1){
		string s, t;
		cin >> s >> t;
		vector<pair<char, int>> vs, vt;
		int cnt = 0;
		char c = 0;
		for(int i = 0; i < (int)s.size(); i += 1){
			if(i == 0 or s[i] != s[i - 1]){
				if(cnt) vs.push_back(make_pair(c, cnt));
				c = s[i];
				cnt = 1;
			}
			else cnt += 1;
		}
		if(cnt) vs.push_back(make_pair(c, cnt));
		cnt = 0;
		for(int i = 0; i < (int)t.size(); i += 1){
			if(i == 0 or t[i] != t[i - 1]){
				if(cnt) vt.push_back(make_pair(c, cnt));
				c = t[i];
				cnt = 1;
			}
			else cnt += 1;
		}
		if(cnt) vt.push_back(make_pair(c, cnt));
		bool ok = true;
		if(vs.size() != vt.size()) ok = false;
		else for(int i = 0; i < (int)vs.size(); i += 1)
				if(vs[i].first != vt[i].first or vs[i].second > vt[i].second) ok = false;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}