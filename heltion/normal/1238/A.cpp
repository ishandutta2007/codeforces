//Author: Heltion
//Date: 10-08-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = -1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i += 1){
		LL x, y;
		cin >> x >> y;
		if(x >= y + 2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}