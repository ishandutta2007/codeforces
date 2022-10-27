#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> cnt(2);
	for(int i = 0; i < (n << 1); i++){
		int x;
		cin >> x;
		cnt[x&1]++;
	}
	if(cnt[0] == n){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}