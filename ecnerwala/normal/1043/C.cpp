#include<bits/stdc++.h>
using namespace std;

bool rev[2000];

int main() {
	string S;
	cin >> S;
	char first = S[0];
	for (int i = 1; i < int(S.size()); i++) {
		if (S[i] <= first) {
			rev[i-1] = !rev[i-1];
			rev[i] = true;
			first = S[i];
		}
	}
	for (int i = 0; i < int(S.size()); i++) {
		cout << (rev[i] ? "1" : "0") << " \n"[i+1 == int(S.size())];
	}
	return 0;
}