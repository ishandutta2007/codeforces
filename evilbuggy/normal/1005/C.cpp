#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n);
	multiset<long long> mst;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mst.insert(a[i]);
	}
	int ans = n;
	for(int i = 0; i < n; i++){
		mst.erase(mst.find(a[i]));
		for(int j = 0; j < 40; j++){
			if(mst.count((1LL << j) - a[i])){
				ans--;
				break;
			}
		}
		mst.insert(a[i]);
	}
	cout << ans << '\n';

	return 0;
}