#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << a[0] << '\n';
	}else{
		sort(a.begin(), a.end());
		for(int i = 1; i < n; i++){
			a[i] += a[i - 1];
		}
		cout << a[n - 1] - 2*(*min_element(a.begin(), a.begin() + n - 1)) << '\n';
	}

	return 0;
}