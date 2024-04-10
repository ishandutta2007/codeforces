#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int k; cin >> k;
		map<int, int> frmap;
		for(int i = 0; i < n; i++){
			int x; cin >> x; frmap[x]++;
		}
		int l = -1, r = -2;
		int L = -1, R = -2;
		for(auto x : frmap){
			if(x.second < k)continue;
			if(r + 1 == x.first){
				r++;
			}else{
				if(R - L + 1 < r - l + 1){
					L = l; R = r;
				}
				l = r = x.first;
			}
		}
		if(R - L + 1 < r - l + 1){
			L = l; R = r;
		}
		if(L == -1){
			cout << -1 << '\n';
		}else{
			cout << L << " " << R << '\n';
		}
	}

	return 0;
}