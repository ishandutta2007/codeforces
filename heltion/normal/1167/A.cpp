//Author: Heltion
//Date: 2019-05-15
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
	int t;
	for(cin >> t; t; t -= 1){
		int n;
		string s;
		cin >> n >> s;
		bool ok = false;
		for(int i = 0; i < n - 10; i += 1) ok |= s[i] == '8';
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}