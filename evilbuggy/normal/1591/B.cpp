#include <bits/stdc++.h>
using namespace std;

const int maxN = 200005;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		reverse(a.begin(), a.end());
		int prev = a[0], answer = 0;
		for(int i = 1; i < n; i++){
			if(a[i] > prev){
				answer++;
				prev = a[i];
			}
		}
		cout << answer << '\n';
	}

	return 0;
}