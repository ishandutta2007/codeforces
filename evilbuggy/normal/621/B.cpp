#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<int, int> diag1cnt;
	map<int, int> diag2cnt;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		diag1cnt[x + y]++;
		diag2cnt[x - y]++;
	}
	long long answer = 0;
	for(auto x : diag1cnt){
		answer += x.second*1LL*(x.second - 1)/2;
	}
	for(auto x : diag2cnt){
		answer += x.second*1LL*(x.second - 1)/2;
	}
	cout << answer << '\n';

	return 0;
}