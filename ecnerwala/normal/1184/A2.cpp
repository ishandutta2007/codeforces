#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<int> v;
	for(int d = 1; d * d <= n; d++){
		if(n % d == 0){
			v.insert(d);
			v.insert(n / d);
		}
	}
	vector<int> phi(n+1, 0);
	for(int d = 1; d <= n; d++) phi[d] = d;
	for(int d = 1; d <= n; d++){
		for(int e = d + d; e <= n; e += d){
			phi[e] -= phi[d];
		}
	}
	int ans = 0;
	for(int d : v){
		vector<int> sums(d, 0);
		for(int i = 0; i < n; i++){
			sums[i % d] ^= (s[i] - '0');
		}
		bool works = true;
		for(int x : sums){
			if(x) works = false;
		}
		if(works){
			ans += phi[n/d];
		}
	}
	cout << ans << '\n';
}