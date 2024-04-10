#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, d;
	cin >> n >> m >> d;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	vector<int> ans(n);
	sort(a.begin(), a.end());
	set<pair<int, int> > breaksSet;
	for(int i = 0; i < n; i++){
		if(breaksSet.empty()){
			ans[a[i].second] = 0;
			breaksSet.insert({a[i].first, 0});
		}else{
			int mn = breaksSet.begin()->first;
			if(mn < a[i].first - d){
				auto it = breaksSet.upper_bound(make_pair(a[i].first - d, -1));
				assert(it != breaksSet.begin()); it--;
				ans[a[i].second] = it->second;
				breaksSet.erase(it);
				breaksSet.insert({a[i].first, ans[a[i].second]});
			}else{
				ans[a[i].second] = (int)breaksSet.size();
				breaksSet.insert({a[i].first, ans[a[i].second]});
			}
		}
	}
	cout << 1 + (*max_element(ans.begin(), ans.end())) << '\n';
	for(int i = 0; i < n; i++){
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';

	return 0;
}