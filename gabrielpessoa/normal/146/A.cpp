#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int n;
	int soma1 = 0, soma2 = 0;
	cin >> n >> s;
	for(int i = 0; i < n/2; i++) {
		soma1 += s[i]-'0';
		if(s[i] != '4' && s[i] != '7') {
			puts("NO");
			return 0;
		}
	}
	for(int i = n/2; i < n; i++) {
		soma2 += s[i]-'0';
		if(s[i] != '4' && s[i] != '7') {
			puts("NO");
			return 0;
		}
	}
	if(soma1 == soma2) {
		puts("YES");
	} else {
		puts("NO");
}
}