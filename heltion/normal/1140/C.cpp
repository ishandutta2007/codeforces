#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
pair<LL, LL> p[maxn];
multiset<LL> s;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i += 1) cin >> p[i].second >> p[i].first;
	sort(p, p + n, greater<pair<LL, LL>>());
	LL ans = 0, sum = 0;
	for(int i = 0; i < n; i += 1){
		s.insert(p[i].second);
		sum += p[i].second;
		if(s.size() > k){
			sum -= *s.begin();
			s.erase(s.begin());
		} 
		ans = max(ans, sum * p[i].first);
	}
	cout << ans;
}