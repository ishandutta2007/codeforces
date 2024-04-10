#include <bits/stdc++.h>
using namespace std;

vector <long long> all;

void dfs(long long x, int cnt){
	if (x > 100000000000ll) return ;
	if (cnt == 0) all.push_back(x);
	dfs(x * 10 + 4, cnt + 1);
	dfs(x * 10 + 7, cnt - 1);
}

int main(){
	dfs(0, 0);
	sort(all.begin(), all.end());
	long long n; cin >> n;
	cout << all[lower_bound(all.begin(), all.end(), n) - all.begin()] << endl;
	return 0;
}