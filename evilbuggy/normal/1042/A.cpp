#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mxans = 0;
	for(int i = 0; i < n; i++){
		mxans = max(mxans, m + a[i]);
	}
	while(m--){
		int ind = 0;
		for(int i = 1; i < n; i++){
			if(a[ind] > a[i])ind = i;
		}
		a[ind]++;
	}
	int mnans = 0;
	for(int i = 0; i < n; i++){
		mnans = max(mnans, a[i]);
	}
	cout << mnans << ' ' << mxans << '\n';

	return 0;
}