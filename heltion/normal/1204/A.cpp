//Author: Heltion
//Date: 08-20-2019
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
	string s;
	cin >> s;
	int ans = (s.size() + 1) / 2;
	if(s.size() % 2 == 0) no(ans);
	for(int i = 1; i < (int)s.size(); i += 1) if(s[i] == '1') no(ans);
	cout << ans - 1;
	return 0;
}