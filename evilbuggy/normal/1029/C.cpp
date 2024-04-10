#include <bits/stdc++.h>
using namespace std;

inline int length(int l, int r){
	return max(0, r - l);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	vector<int> pmxl = l;
	vector<int> pmnr = r;
	vector<int> smxl = l;
	vector<int> smnr = r;
	for(int i = 1; i < n; i++){
		pmxl[i] = max(pmxl[i], pmxl[i - 1]);
		pmnr[i] = min(pmnr[i], pmnr[i - 1]);
	}
	for(int i = n - 2; i >= 0; i--){
		smxl[i] = max(smxl[i], smxl[i + 1]);
		smnr[i] = min(smnr[i], smnr[i + 1]);
	}
	int ans = length(smxl[1], smnr[1]);
	for(int i = 1; i + 1 < n; i++){
		ans = max(ans, length(max(pmxl[i - 1], smxl[i + 1]), min(pmnr[i - 1], smnr[i + 1])));
	}
	ans = max(ans, length(pmxl[n - 2], pmnr[n - 2]));
	cout << ans << '\n';

	return 0;
}