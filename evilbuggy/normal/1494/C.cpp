#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int solve(vector<int> &a, vector<int> &b){
	if(a.empty() || b.empty())return 0;
	int n = (int)a.size();
	int m = (int)b.size();
	vector<int> suff_sum(n + 1);
	for(int i = 0, j = 0; i < n; i++){
		while(j < m && b[j] < a[i])j++;
		if(j < m && b[j] == a[i])suff_sum[i] = 1;
	}
	for(int i = n - 1; i >= 0; i--){
		suff_sum[i] += suff_sum[i + 1];
	}
	int ret = suff_sum[0];
	for(int pos = 0, ind = 0, r = -1; pos < m; pos++){
		while(ind < n && a[ind] - ind <= b[pos])ind++;
		while(r + 1 < m && b[r + 1] < b[pos] + ind)r++;
		ret = max(ret, r - pos + 1 + suff_sum[ind]);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> ap, an, bp, bn;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			if(x < 0)an.push_back(-x);
			else ap.push_back(x);
		}
		for(int i = 0; i < m; i++){
			int x; cin >> x;
			if(x < 0)bn.push_back(-x);
			else bp.push_back(x);
		}
		reverse(an.begin(), an.end());
		reverse(bn.begin(), bn.end());
		cout << solve(an, bn) + solve(ap, bp) << '\n';
	}

	return 0;
}