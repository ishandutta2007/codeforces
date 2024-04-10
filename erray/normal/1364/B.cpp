#include<bits/stdc++.h>         	

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {	
			cin >> a[i];
		}
		vector<int> ans;	
		ans.push_back(a[0]);
		for (int i = 1; i < n - 1; ++i) if ((a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) ans.push_back(a[i]);
		cout << ans.size() + 1 << '\n';
		for (int a : ans) cout << a << ' ';
		cout << a[n - 1] << '\n'; 
	}
}