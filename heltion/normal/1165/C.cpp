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
	int n;
	string s, t;
	cin >> n >> s;
	for(int i = 0; i < n; i += 1)
		if(t.size() % 2 == 0) t.push_back(s[i]);
		else if(s[i] != t.back()) t.push_back(s[i]);
	if(t.size() & 1) t.pop_back();
	cout << n - t.size() << endl << t;
	return 0;
}