#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	int e = 0, o = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i]&1)o = 1;
		else e = 1;
	}
	if(o == 1 && e == 1){
		sort(a.begin(), a.end());
	}
	for(auto x : a){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}