#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for(auto ch : {'a', 'b', 'c', 'd', 'e'}){
			vector<int> vec;
			for(int i = 0; i < n; i++){
				int val = 0;
				for(auto sh : a[i]){
					if(ch == sh){
						val++;
					}else{
						val--;
					}
				}
				vec.emplace_back(val);
			}
			sort(vec.rbegin(), vec.rend());
			int sum = 0;
			for(int i = 0; i < n; i++){
				sum += vec[i];
				if(sum <= 0){
					break;
				}
				ans = max(ans, i + 1);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}