//Author: Heltion
//Date: 2019-05-17
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 120;
char s[maxn];
int c[26];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> s;
		c[*s - 'a'] += 1;
	}
	for(int i = 0; i < 26; i += 1)
		ans += (c[i] / 2) * ((c[i] / 2) - 1) / 2 + ((c[i] + 1) / 2) * (((c[i] + 1) / 2) - 1) / 2;
	cout << ans;
	return 0;
}