#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n%2 == 0){
		cout << "YES" << '\n';
	}else{
		for(int i = 1; i < n; i++){
			if(a[i - 1] >= a[i]){
				cout << "YES" << '\n';
				return;
			}
		}
		cout << "NO" << '\n';
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