//Author: Heltion
//Date: 2019-04-24
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int a[2], b[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1){
		cin >> x;
		a[x & 1] += 1;
	}
	for(int i = 0; i < m; i += 1){
		cin >> x;
		b[x & 1] += 1;
	}
	cout << min(a[0], b[1]) + min(a[1], b[0]);
	return 0;
}