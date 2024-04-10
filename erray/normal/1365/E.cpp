#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	long long ans = 0;
	for (int i = 0; i < 2; ++i) a.push_back(0);
	n += 2;	
	for (int i = 0; i < n; ++i) for (int j =  i + 1; j < n; ++j) for(int q = j + 1; q < n; ++q) ans = max(ans, a[i] | a[j] | a[q]);
	cout << ans << '\n';
}