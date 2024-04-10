#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N], st[N], en[N], f[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	memset(st, -1, sizeof(st));
	memset(en, -1, sizeof(en));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		en[a[i]] = i;
		if(st[a[i]] == -1)st[a[i]] = i;
	}
	vector<pair<int, int> > vec;
	for(int i = 1; i < N; i++){
		if(st[i] != -1)vec.emplace_back(st[i], en[i]);
	}
	int cur = 0;
	vector<pair<int, int> > res;
	sort(vec.begin(), vec.end());
	for(auto x : vec){
		if(cur < x.first){
			res.push_back(x);
		}else{
			res.back().second = max(res.back().second, x.second);
		}
		cur = res.back().second;
	}
	int ans = 0;
	memset(f, 0, sizeof(f));
	for(auto x : res){
		int l = x.first, r = x.second;
		for(int i = l; i <= r; i++){
			f[a[i]]++;
		}
		int mx = 0;
		for(int i = l; i <= r; i++){
			mx = max(mx, f[a[i]]);
			f[a[i]] = 0;
		}
		ans += (r - l + 1) - mx;
	}
	cout << ans << '\n';

	return 0;
}