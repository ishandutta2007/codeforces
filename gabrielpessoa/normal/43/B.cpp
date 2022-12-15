#include <bits/stdc++.h>
using namespace std;

int maiuscula[30];
int minuscula[30];

int main() {
	string a, b;
	bool pode = true;
	getline(cin, a);
	getline(cin, b);
	for(int i = 0; i < a.length(); i++) {
		if(a[i] >= 'a' && a[i] <= 'z') {
			minuscula[a[i]-'a']++;
		} else if(a[i] >= 'A' && a[i] <= 'Z') {
			maiuscula[a[i]-'A']++;
		}
	}
	for(int i = 0; i < b.length(); i++) {
		if(b[i] >= 'a' && b[i] <= 'z') {
			if(minuscula[b[i]-'a']-- == 0) {
				pode = false;
				break;
			}
		} else if(b[i] >= 'A' && b[i] <= 'Z') {
			if(maiuscula[b[i]-'A']-- == 0) {
				pode = false;
				break;
			}
		}
	}
	if(pode) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}