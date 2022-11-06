//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200000;
pair<int, int> p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1)
			p[(i - 1) * m + j] = make_pair(i, j);
	int L = 1, R = n * m;
	while(L <= R){
		cout << p[L].first << " " << p[L].second << "\n";
		L += 1;
		if(L > R) break;
		cout << p[R].first << " " << p[R].second << "\n";
		R -= 1;
	}
	return 0;
}