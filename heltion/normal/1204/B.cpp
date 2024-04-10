//Author: Heltion
//Date: 08-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
LL mi(LL n, LL l, LL r){
	LL res = 0;
	for(int i = 0; i < l; i += 1) res += 1 << i;
	res += n - l;
	return res;
}
LL ma(LL n, LL l, LL r){
	LL res = 0;
	for(int i = 0; i < r; i += 1) res += 1 << i;
	res += (n - r) << (r - 1);
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, l, r;
	cin >> n >> l >> r;
	cout << mi(n, l, r) << " " << ma(n, l, r);
	return 0;
}