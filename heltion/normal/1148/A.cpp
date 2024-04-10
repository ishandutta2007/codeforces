//Author: Heltion
//Date: 2019-06-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL a, b, c;
	cin >> a >> b >> c;
	cout << 2 * c + 2 * min(a, b) + (a != b);
	return 0;
}