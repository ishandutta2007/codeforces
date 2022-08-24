#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

bool is_vowel(char c) {
	return c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i' || c == 'y';
}

int main(){

	int n = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = nxt();
	}
	scanf("\n");

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		for (char c : s) {
			if (is_vowel(c)) {
				p[i]--;
			}
		}
		if (p[i]) {
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");

	return 0;
}