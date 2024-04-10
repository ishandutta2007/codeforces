//Author: Heltion
//Date: 09-19-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int n, ans = 0;
		cin >> n;
		for(int i = 0, s; i < n; i += 1){
			cin >> s;
			if(s <= 2048) ans += s;
		}
		cout << (ans >= 2048 ? "YES\n" : "NO\n");
	}
	return 0;
}