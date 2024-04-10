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
		map<int, int> mp;
		int n;
		cin >> n;
		for(int i = 1, a; i <= n; i += 1){
			cin >> a;
			mp[a] += 1;
		}
		priority_queue<int> q;
		for(auto p : mp) q.push(p.second);
		int ans = 0;
		for(int x = 1e9; x and not q.empty();){
			int u = q.top();
			q.pop();
			ans += x = min(x - 1, u);
		}
		cout << ans << "\n";
	}
	return 0;
}