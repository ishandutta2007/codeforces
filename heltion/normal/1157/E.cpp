// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
multiset<int> ms;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int j = 1, b; j <= n; j += 1){
		cin >> b;
		ms.insert(b);
	}
	for(int i = 1; i <= n; i += 1){
		auto it = ms.lower_bound(n - a[i]);
		if(it == ms.end()) it = ms.begin();
		cout << (a[i] + *it) % n << " ";
		ms.erase(it); 
	}
	return 0;
}