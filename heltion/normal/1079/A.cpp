#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for(int i = 0; i < n; i += 1){
		int t;
		cin >> t;
		mp[t] += 1;
	}
	int a = 0;
	for(auto p : mp) a = max(a, p.second);
	cout << (a + k - 1) / k * k * mp.size() - n;
}