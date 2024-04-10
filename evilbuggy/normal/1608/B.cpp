#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a + b > n - 2 || abs(a - b) > 1){
		cout << -1 << '\n';
		return;
	}
	if(a > b){
		int cur = 2;
		cout << 1 << " ";
		while(a > 0 && b > 0){
			cout << cur + 1 << " " << cur << " ";
			cur += 2; a--; b--;
		}
		for(int i = n; i >= cur; i--){
			cout << i << " ";
		}
		cout << '\n';
	}else if(a < b){
		int cur = n - 1;
		cout << n << " ";
		while(a > 0 && b > 0){
			cout << cur - 1 << " " << cur << " ";
			cur -= 2; a--; b--;
		}
		for(int i = 1; i <= cur; i++){
			cout << i << " ";
		}
		cout << '\n';
	}else{
		int cur = 2;
		cout << 1 << " ";
		while(a > 0 && b > 0){
			cout << cur + 1 << " " << cur << " ";
			cur += 2; a--; b--;
		}
		for(int i = cur; i <= n; i++){
			cout << i << " ";
		}
		cout << '\n';
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