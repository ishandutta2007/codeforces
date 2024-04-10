#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;
const long long inf = 1e15;

long long a[maxn], f[maxn], g[maxn], dp[maxn];

inline void update(int i, int n, long long x){
	while(i <= n){
		f[i] = max(f[i], x);
		i += i&(-i);
	}
}

inline long long query(int i){
	long long ret = -inf;
	while(i){
		ret = max(ret, f[i]);
		i &= i - 1;
	}
	return ret;
}

void solve(){
	int n;
	cin >> n;
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	vector<long long> vec;
	for(int i = 0; i <= n; i++){
		vec.emplace_back(a[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

	int s = (int)vec.size();
	for(int i = 1; i <= s; i++){
		f[i] = -inf;
		g[i] = -inf;
	}
	{
		int ind = lower_bound(vec.begin(), vec.end(), a[0]) - vec.begin();
		
		dp[0] = 0;
		g[ind + 1] = 0;
		update(ind + 1, s, 0);
	}
	for(int i = 1; i <= n; i++){
		int ind = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();

		if(a[i] > a[i - 1]){
			dp[i] = dp[i - 1] + 1;
		}else if(a[i] < a[i - 1]){
			dp[i] = dp[i - 1] - 1;
		}else{
			dp[i] = dp[i - 1];
		}
		dp[i] = max({dp[i], g[ind + 1], query(ind) + i});
		update(ind + 1, s, dp[i] - i);
	}
	cout << dp[n] << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}