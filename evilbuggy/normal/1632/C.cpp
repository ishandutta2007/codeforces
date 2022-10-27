#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		int a; cin >> a;
		int b; cin >> b;
		int ans = b - a;
		for(int x = 0; x < b - a; x++){
			int p = a + x;
			for(int i = 19; i >= 0; i--){
				if((p >> i) & 1){
					// do nothing
				}else{
					int q = (((p >> i) + 1) << i) - 1;
					if(q < b){
						p ^= 1 << i;
					}
				}
			}
			ans = min(ans, x + p - b + 1);
		}
		cout << ans << '\n';
	}

	return 0;
}