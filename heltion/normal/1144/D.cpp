#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 240000;
map<int, int> mp;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		mp[a[i]] += 1;
	}
	int m = 0, ma = 0;
	for(auto p : mp)if(p.second > m){
		m = p.second;
		ma = p.first;
	}
	cout << n - m << "\n";
	int L = 0;
	for(int i = 1; i <= n; i += 1) if(a[i] == ma){
		for(int j = i - 1; j > L; j -= 1){
			if(a[j] < ma) cout << 1 << " " << j << " " << j + 1 << "\n";
			else cout << 2 << " " << j << " " << j + 1 << "\n";
		}
		L = i;
	}
	for(int i = L + 1; i <= n; i += 1){
		if(a[i] < ma) cout << 1 << " " << i << " " << i - 1 << "\n";
		else cout << 2 << " " << i << " " << i - 1 << "\n";
	}
}