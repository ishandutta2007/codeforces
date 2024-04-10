//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}

constexpr int maxn = 30;
constexpr int maxr = 1200;
int s[maxn], f[maxr];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, r, b = 0;
	cin >> n >> m >> r;
	for(int i = 0; i < n; i += 1) cin >> s[i];
	for(int i = 0, x; i < m; i += 1){
		cin >> x;
		b = max(b, x);
	}
	for(int i = 1; i <= r; i += 1){
		f[i] = i;
		for(int j = 0; j < n; j += 1) if(i >= s[j]) maxi(f[i], f[i - s[j]] + b);
	}
	cout << f[r];
	return 0;
}