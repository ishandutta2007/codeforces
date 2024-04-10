#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n << 1);
	for(auto &x : a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	if(a[0] == a.back()){
		cout << -1 << '\n';
	}else{
		for(auto x : a){
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}