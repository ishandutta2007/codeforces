#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> ans(n + 1);
	for(int i = 2, j = 1; i <= n; i++){
		if(!ans[i]){
			for(int k = i; k <= n; k += i){
				if(!ans[k])ans[k] = j;
			}
			++j;
		}
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}