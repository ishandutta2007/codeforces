#include<bits/stdc++.h>

using namespace std;


const string ev[] = 
{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"}
;

bool matches(string pat, string str) {
	if(pat.size() != str.size()) return false;
	for(int i = 0; i < int(pat.size()); i++) {
		if(pat[i] == '.') continue;
		if(pat[i] != str[i]) return false;
	}
	return true;
}

int main() {
	int n; cin >> n;
	string s; cin >> s;

	for(int i = 0; i < 8; i++) {
		if(matches(s, ev[i])) cout << ev[i] << '\n';
	}
	return 0;
}