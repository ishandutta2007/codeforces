#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int a[maxn], l[maxn], dp[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; l[i] = 0;
	}
	vector<pair<int, int> > gcds;
	for(int i = 1; i <= n; i++){
		gcds.emplace_back(a[i], 1);
		vector<pair<int, int> > ngcds;
		for(auto x : gcds){
			int g = __gcd(x.first, a[i]);
			if(ngcds.empty() || ngcds.back().first != g){
				ngcds.emplace_back(g, x.second);
			}else{
				ngcds.back().second += x.second;
			}
		}
		gcds = ngcds;

		int cur = 0;
		for(int j = (int)gcds.size() - 1; j >= 0; j--){
			int g = gcds[j].first, c = gcds[j].second;
			if(cur < g && g <= cur + c){
				l[i] = i - g + 1;
				break;
			}
			cur += c;
		}
	}
	dp[0] = 0;
	vector<int> vec({0});
	for(int i = 1; i <= n; i++){
		if(l[i] == 0){
			dp[i] = dp[i - 1];
		}else{
			int x = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
			x = vec[x - 1]; dp[i] = dp[x] + 1;
			vec.emplace_back(i);
		}
		cout << dp[i] << " ";
	}
	cout << '\n';

	return 0;
}