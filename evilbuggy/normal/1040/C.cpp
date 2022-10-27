#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long t;
	cin >> n >> t;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
		x[i]--;
	}
	vector<int> prefixsums(n);
	for(int i = 0; i < n; i++){
		if(x[i] < i){
			cout << "No" << '\n';
			exit(0);
		}
		prefixsums[i]++;
		prefixsums[x[i]]--;
		if(i){
			prefixsums[i] += prefixsums[i - 1];
		}
	}
	vector<long long> lb(n, LLONG_MIN);
	vector<long long> ub(n, LLONG_MAX);
	for(int i = 0; i < n; i++){
		lb[i] = max(lb[i], a[i] + t);
		if(prefixsums[i]){
			lb[i] = max(lb[i], a[i + 1] + t);
		}
		if(x[i] + 1 < n){
			ub[x[i]] = min(ub[x[i]], a[x[i] + 1] + t - 1);
		}
	}
	long long cur = 0;
	vector<long long> ans(n);
	for(int i = 0; i < n; i++){
		cur = max(cur + 1, lb[i]);
		if(cur > ub[i]){
			cout << "No" << '\n';
			exit(0);
		}
		ans[i] = cur;
	}
	cout << "Yes" << '\n';
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}