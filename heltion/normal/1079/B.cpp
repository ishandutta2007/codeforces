#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n = (s.size() + 19) / 20, m = (s.size() + n - 1) / n;
	cout << n << " " << m << endl;
	int p = 0, L;
	for(int i = 0; i < n; i += 1){
		if(i < n * m - s.size()) L = m - 1;
		else L = m;
		cout << s.substr(p, L);
		if(L != m) cout << "*";
		cout << endl;
		p += L;
	}
}