#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mn = *min_element(a.begin(), a.end());
	int mx = *max_element(a.begin(), a.end());
	int answer = 0;
	for(int i = 0; i < n; i++){
		if(mn < a[i] && a[i] < mx)answer++;
	}
	cout << answer << '\n';

	return 0;
}