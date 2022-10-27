#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

int f[maxN];
long long a[maxN];

inline void update(int i, int x, int n){
	while(i <= n){
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i){
	int ret = 0;
	while(i){
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long t;
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		a[i] += a[i - 1];
	}
	vector<long long> vec;
	for(int i = 0; i <= n; i++){
		vec.emplace_back(a[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

	long long ans = 0;
	int m = (int)vec.size();
	for(int i = n; i >= 0; i--){
		if(i != n){
			int ind = 1 + (int)(lower_bound(vec.begin(), vec.end(), a[i] + t) - vec.begin());
			ans += query(ind - 1);
		}
		int ind = 1 + (int)(lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin());
		update(ind, 1, m);
	}
	cout << ans << '\n';

	return 0;
}