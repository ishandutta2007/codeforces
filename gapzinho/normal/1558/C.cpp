#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 4e6+5;

int arr[ms];

int getIdxOf(int k) {
	for(int i = 0; i < ms; i++) {
		if(arr[i] == k) return i+1;
	}
	return 0;
}

main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		vector<int> ans;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		bool possible = 1;
		for(int i = 0; i < n; i++) {
			if(arr[i] % 2 == i % 2) {
				possible = 0;
			}
		}
		if(possible) {
			for(int x = n; x >= 3; x-=2) {
				int a = getIdxOf(x);
				ans.push_back(a);
				reverse(arr, arr+a);
				int b = getIdxOf(x-1); 
				ans.push_back(b-1);
				reverse(arr, arr+b-1);
				ans.push_back(b+1);
				reverse(arr, arr+b+1);
				ans.push_back(3);
				reverse(arr, arr+3);
				ans.push_back(x);
				reverse(arr, arr+x);
				// cout << "want " << x-1 << " and " << x << " -> ";
				// cout << arr[x-2] << ' ' << arr[x-1] << endl;
			}
			cout << ans.size() << '\n';
			for(int x : ans) cout << x << ' ';
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}