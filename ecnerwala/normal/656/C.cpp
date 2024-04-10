#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int res = 0;
	for(char c : str) {
		if('@' < c && c < '[') res += c - '@';
		else if('`' < c && c < '{') res -= c - '`';
	}
	cout << res << '\n';
	return 0;
}