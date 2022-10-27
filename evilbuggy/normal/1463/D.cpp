#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> x(n);
		for(auto &a : x){
			cin >> a;
		}
		vector<int> y(n);
		set<int> st;
		for(auto a : x){
			st.insert(a);
		}
		for(int i = 0, j = 1; i < n; i++){
			while(st.find(j) != st.end())j++;
			y[i] = j; j++;
		}
		int ans = 0;
		bool flg = true;
		for(int i = 0; i < n; i++){
			if(x[i] < y[i]){
				flg = false;
				break;
			}
		}
		if(flg)ans++;
		vector<int> pref(n), suff(n);
		for(int i = 0; i < n; i++){
			int ind = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
			pref[i] = n - ind + i;
			if(i){
				pref[i] = min(pref[i], pref[i - 1]);
			}
		}
		for(int i = n - 1; i >= 0; i--){
			int ind = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
			suff[i] = ind + n - 1 - i;
			if(i + 1 < n){
				suff[i] = min(suff[i], suff[i + 1]);
			}
		}
		for(int i = 0; i + 1 < n; i++){
			if(pref[i] >= i + 1 && suff[i + 1] >= n - i - 1)ans++;
		}
		if(pref[n - 1] >= n)ans++;
		cout << ans << '\n';
	}

	return 0;
}