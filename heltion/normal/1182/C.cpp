//Author: Heltion
//Date: 2019-06-11
#include<bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
constexpr int maxn = 120000;
map<int, set<int>> mpc[5];
map<int, set<int>> mp;
map<char, int> num;
string s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	num['a'] = 0;
	num['e'] = 1;
	num['i'] = 2;
	num['o'] = 3;
	num['u'] = 4;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> s[i];
		int cv = 0;
		char sv;
		for(char c : s[i])
			if(num.count(c)){
				cv += 1;
				sv = c;
			}
		mpc[num[sv]][cv].insert(i);
	}
	vector<pair<int, int>> ans[2];
	for(int i = 0; i < 5; i += 1){
		for(auto &p : mpc[i]){
			const int &cv = p.first;
			auto &s = p.second;
			int o = 0;
			pair<int, int> np;
			for(int x : s){
				if(o == 0) np.first = x;
				else{
					np.second = x;
					ans[0].push_back(np);
				}
				o ^= 1;
			}
			if(o) mp[cv].insert(np.first);
		}
	}
	for(auto &p : mp){
			const int &cv = p.first;
			auto &s = p.second;
			int o = 0;
			pair<int, int> np;
			for(int x : s){
				if(o == 0) np.first = x;
				else{
					np.second = x;
					ans[1].push_back(np);
				}
				o ^= 1;
			}
			if(o) mp[cv].insert(np.first);
		}
	while(ans[0].size() > ans[1].size()){
		ans[1].push_back(ans[0].back());
		ans[0].pop_back();
	}
	cout << ans[0].size() << "\n";
	for(int i = 0; i < (int)ans[0].size(); i += 1){
		cout << s[ans[1][i].first] << " " << s[ans[0][i].first] << "\n"; 
		cout << s[ans[1][i].second] << " " << s[ans[0][i].second] << "\n";
	}
	return 0;
}