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
	vector<char> v[2];
	for(char c : s) v[c % 2].push_back(c);
	merge(v[0].begin(), v[0].end(), v[1].begin(), v[1].end(), s.begin());
	cout << s << "\n";
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