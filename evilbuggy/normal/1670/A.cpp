#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int neg = 0;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] < 0){
				neg++;
			}
		}
		for(int i = 0; i < n; i++){
			if(i < neg){
				a[i] = -abs(a[i]);
			}else{
				a[i] = abs(a[i]);
			}
		}
		bool flg = true;
		for(int i = 1; i < n; i++){
			if(a[i] < a[i - 1]){
				flg = false;
			}
		}
		if(flg)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}