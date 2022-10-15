#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		vector<int> v(n); 
		for (int i = 0; i < n; ++i) cin >> v[i];
		int sum = 0, lst = -1, ans = 0; 
		for (int i = 0; i < n; ++i) {
			sum += v[i];
			if (sum % x) {
				ans = i + 1;  
				if (lst == -1) lst = i;
			} else if (lst != -1){
				ans = max(ans, i - lst);				
			}
		}
		cout << (ans ? ans : -1) << '\n';
	}
}