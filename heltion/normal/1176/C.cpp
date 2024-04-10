//Author: Heltion
//Date: 2019-06-09
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 6;
int c[maxn], a[maxn] = {4, 8, 15, 16, 23, 42};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	map<int, int> mp;
	for(int i = 0; i < 6; i += 1) mp[a[i]] = i;
	int n;
	cin >> n;
	for(int i = 0, x; i < n; i += 1){
		cin >> x;
		x = mp[x];
		if(x == 0 || c[x - 1] > c[x]) c[x] += 1;
	}
	cout << n - c[5] * 6;
	return 0;
}