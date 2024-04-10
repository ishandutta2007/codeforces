#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<int, string> > a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		if(a[i].first > i){
			cout << -1 << '\n';
			exit(0);
		}
	}
	vector<int> used(n);
	for(int i = n - 1; i >= 0; i--){
		int x = a[i].first;
		for(int j = n - 1; j >= 0; j--){
			if(used[j])continue;
			if(x == 0){
				a[i].first = j;
				used[j] = 1;
				break;
			}
			x--;
		}
		assert(x == 0);
	}
	for(int i = 0; i < n; i++){
		cout << a[i].second << " " << a[i].first + 1 << '\n';
	}

	return 0;
}