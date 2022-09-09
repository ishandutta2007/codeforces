#include<bits/stdc++.h>
using namespace std;
using LL = long long;
set<string> s;
int main(){
	int n, m, c = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1){
		string ss;
		cin >> ss;
		s.insert(ss);
	}
	for(int i = 0; i < m; i += 1){
		string ss;
		cin >> ss;
		c += s.count(ss);
	}
	int p = (c + 1) / 2 + n - c, q = c / 2 + m - c;
	cout << (p > q ? "YES" : "NO");
}