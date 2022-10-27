#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	set<int> required;
	for(int i = 0; i < n; i++){
		required.insert(i + 1);
	}
	int answer = 0;
	for(int i = 0; i < n; i++){
		if(required.count(a[i])){
			required.erase(a[i]);
			continue;
		}
		int x = *required.begin();
		if(x <= (a[i] - 1)/2){
			required.erase(x);
			answer++;
		}else{
			cout << -1 << '\n';
			return;
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