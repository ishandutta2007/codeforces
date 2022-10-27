#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int l1; cin >> l1;
		int r1; cin >> r1;
		int l2; cin >> l2;
		int r2; cin >> r2;
		if(max(l1, l2) <= min(r1, r2)){
			cout << max(l1, l2) << '\n';
		}else{
			cout << l1 + l2 << '\n';
		}
	}

	return 0;
}