#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i]; a[i]--;
	}
	vector<int> ans(n);
	for(int i = 0; i < n; i++){
		vector<int> f(n);
		int cnt = 0, ind = 0;
		for(int j = i; j < n; j++){
			f[a[j]]++;
			if(f[a[j]] > cnt){
				cnt = f[a[j]];
				ind = a[j];
			}else if(f[a[j]] == cnt && a[j] < ind){
				ind = a[j];
			}
			ans[ind]++;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}