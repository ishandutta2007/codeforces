#include <bits/stdc++.h>
using namespace std;

inline int computeIndiv(vector<pair<int, int> > items, int money){
	sort(items.begin(), items.end());
	int ret = 0;
	for(int i = 0; i < (int)items.size(); i++){
		int ind = lower_bound(items.begin(), items.begin() + i, make_pair(money - items[i].first + 1, -1)) - items.begin();
		if(ind > 0){
			ret = max(ret, items[i].second + items[ind - 1].second);
		}
		if(i)items[i].second = max(items[i].second, items[i - 1].second);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c, d;
	cin >> n >> c >> d;
	vector<pair<int, int> > coin, diam;
	for(int i = 0; i < n; i++){
		int b, p; char ch;
		cin >> b >> p >> ch;
		if(ch == 'C'){
			if(p <= c){
				coin.emplace_back(p, b);
			}
		}else{
			if(p <= d){
				diam.emplace_back(p, b);
			}
		}
	}
	int ans = 0;
	ans = max(ans, computeIndiv(coin, c));
	ans = max(ans, computeIndiv(diam, d));
	if(!coin.empty() && !diam.empty()){
		int mc = 0, md = 0;
		for(auto x : coin){
			mc = max(mc, x.second);
		}
		for(auto x : diam){
			md = max(md, x.second);
		}
		ans = max(ans, mc + md);
	}	
	cout << ans << '\n';

	return 0;
}