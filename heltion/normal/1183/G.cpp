//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int q;
	for(cin >> q; q; q -= 1){
		map<int, pair<int, int>> mp;
		int n;
		cin >> n;
		for(int i = 1, a, f; i <= n; i += 1){
			cin >> a >> f;
			mp[a].first += 1;
			mp[a].second += f;
		}
		priority_queue<pair<int, int>> q;
		for(auto p : mp) q.push(p.second);
		int ans = 0, ans2 = 0;
		for(int x = 1e9; x and not q.empty();){
			auto u = q.top();
			q.pop();
			if(x > u.first){
				ans += x = u.first;
				ans2 += min(x, u.second);
			}
			else q.push(make_pair(u.first - 1, u.second));
		}
		cout << ans << " " << ans2 << "\n";
	}
	return 0;
}