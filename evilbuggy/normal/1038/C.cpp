#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(a.empty()){
			b.pop_back();
		}else if(b.empty()){
			ans += a.back();
			a.pop_back();
		}else if(a.back() > b.back()){
			ans += a.back();
			a.pop_back();
		}else{
			b.pop_back();
		}

		if(b.empty()){
			a.pop_back();
		}else if(a.empty()){
			ans -= b.back();
			b.pop_back();
		}else if(b.back() > a.back()){
			ans -= b.back();
			b.pop_back();
		}else{
			a.pop_back();
		}
	}
	cout << ans << '\n';

	return 0;
}