//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y, ans = 0;
	string s;
	cin >> n >> x >> y >> s;
	reverse(s.begin(), s.end());
	for(int i = 0; i < y ; i += 1) ans += s[i] == '1';
	ans += s[y] == '0';
	for(int i = y + 1; i < x; i += 1) ans += s[i] == '1';
	cout << ans;
	return 0;
}