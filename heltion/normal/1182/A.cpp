//Author: Heltion
//Date: 2019-06-11
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int n;
	cin >> n;
	cout << (n & 1 ? 0LL : 1LL << (n / 2));
	return 0;
}