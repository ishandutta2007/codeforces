#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> p(n);
		for(int i = 1; i < n; i++){
			cin >> p[i]; p[i]--;
		}
		string s;
		cin >> s;
		vector<int> w(n);
		vector<int> b(n);
		int ans = 0;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == 'W'){
				w[i]++;
			}else{
				b[i]++;
			}
			if(i){
				w[p[i]] += w[i];
				b[p[i]] += b[i];
			}
			if(w[i] == b[i])ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}