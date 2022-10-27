#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		if(a[i] == 0 && a[i - 1] == 0){
			cout << -1 << '\n';
			return;
		}
	}
	int answer = 1;
	for(int i = 0; i < n; i++){
		if(a[i]){
			answer++;
			if(i > 0 && a[i - 1])answer += 4;
		}
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