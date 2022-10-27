#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << max(0, a[2] - a[1] - a[0] + 1) << '\n';

	return 0;
}