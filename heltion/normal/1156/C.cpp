//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
constexpr int maxn = 240000;
int x[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0, z;
	cin >> n >> z;
	for(int i = 0; i < n; i += 1) cin >> x[i];
	sort(x, x + n);
	for(int i = 0, j = n / 2; i < n / 2 and j < n; i += 1){
		while(j < n and x[j] < x[i] + z) j += 1;
		if(j < n) ans += 1, j += 1;
	}
	cout << ans;
	return 0;
}