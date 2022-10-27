#include <bits/stdc++.h>
using namespace std;

void solve(){
	string a;
	int n, p, k;
	cin >> n >> p >> k >> a;
	
	vector<int> cnt(n);
	for(int i = n - 1; i >= 0; i--){
		if(a[i] == '0')cnt[i] = 1;
		if(i + k < n)cnt[i] += cnt[i + k];
	}
	int x, y;
	cin >> x >> y;
	int answer = INT_MAX;
	for(int i = p - 1; i < n; i++){
		answer = min(answer, (i - p + 1)*y + cnt[i]*x);
	}
	cout << answer << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}