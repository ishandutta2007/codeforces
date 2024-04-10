//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
string p[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
bool check(string res, string s, string t){
	for(int i = 0; i + 1 < (int)res.size(); i += 1){
		if(res[i] == s[0] and res[i + 1] == s[1]) return false;
		if(res[i] == t[0] and res[i + 1] == t[1]) return false;
	}
	return true;
}
void check(int i, int j, string s, string t, int n){
	string res;
	if(i == 0) for(int t = 0; t < 3; t += 1) for(int x = 0; x < n; x += 1) res.push_back(p[j][t]);
	if(i == 1) for(int x = 0; x < n; x += 1) for(int t = 0; t < 3; t += 1) res.push_back(p[j][t]);
	if(check(res, s, t)){
		cout << "YES\n";
		no(res);
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	string s, t, res;
	cin >> n >> s >> t;
	for(int i = 0; i < 2; i += 1)
		for(int j = 0; j < 6; j += 1)
			check(i, j, s, t, n);
	assert(0);
	return 0;
}