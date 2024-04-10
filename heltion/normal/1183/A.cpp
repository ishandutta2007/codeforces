//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int f(int n){
	int res = 0;
	for(; n; n /= 10) res += n % 10;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int a;
	cin >> a;
	for(; f(a) % 4; a += 1);
	cout << a;
	return 0;
}