//Author: Heltion
//Date: 10-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = -1;
void solve(){
	string s;
	cin >> s;
	char p = 0;
	set<char> sc;
	for(char c : s)
		if(c == p) p = 0;
		else sc.insert(p), p = c;
	sc.insert(p);
	for(auto p : sc) if(p) cout << p;
	cout << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1) solve();
	return 0;
}