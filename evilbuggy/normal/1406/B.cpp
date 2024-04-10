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
		int zero = 0;
		vector<int> neg, pos;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x > 0)pos.push_back(x);
			else if(x < 0)neg.push_back(x);
			else zero++;
		}
		long long ans = LLONG_MIN;
		
		if(zero)ans = 0;
		int ps = (int)pos.size();
		int ns = (int)neg.size();
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		for(int i = 0; i <= 5; i += 2){
			if(ns < i || ps < 5 - i)continue;
			long long prod = 1;
			for(int j = 0; j < i; j++){
				prod *= neg[j];
			}
			for(int j = 0; j < 5 - i; j++){
				prod *= pos[ps - 1 - j];
			}
			ans = max(ans, prod);
		}
		for(int i = 0; i <= 5; i += 2){
			if(ps < i || ns < 5 - i)continue;
			long long prod = 1;
			for(int j = 0; j < i; j++){
				prod *= pos[j];
			}
			for(int j = 0; j < 5 - i; j++){
				prod *= neg[ns - 1 - j];
			}
			ans = max(ans, prod);
		}
		cout << ans << '\n';
	}

	return 0;
}