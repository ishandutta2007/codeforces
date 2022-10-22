#include <bits/stdc++.h>
using namespace std;

string buf, s;
map <string, int> mp;

// 3 ok   2 /   1 -/   0 -/*
int check(int l, int r){
	if (mp.count(s.substr(l, r - l + 1))) return mp[s.substr(l, r - l + 1)];
	int t = 0;
	for (int i = r; i >= l; i--){
		if (s[i] == ')') t++;
		if (s[i] == '(') t--;
		if (t != 0) continue;
		if (s[i] == '+'){
			int t1 = check(l, i - 1), t2 = check(i + 1, r);
			if (t1 == 0 || t2 == 0) return 0;
			return 1;
		}
		if (s[i] == '-'){
			int t1 = check(l, i - 1), t2 = check(i + 1, r);
			if (t1 == 0 || t2 <= 1) return 0;
			return 1;
		}
	}
	for (int i = r; i >= l; i--){
		if (s[i] == ')') t++;
		if (s[i] == '(') t--;
		if (t != 0) continue;
		if (s[i] == '*'){
			int t1 = check(l, i - 1), t2 = check(i + 1, r);
			if (t1 <= 1 || t2 <= 1) return 0;
			return 2;
		}
		if (s[i] == '/'){
			int t1 = check(l, i - 1), t2 = check(i + 1, r);
			if (t1 <= 1 || t2 <= 2) return 0;
			return 2;
		}
	}
	if (s[l] == '(' && s[r] == ')') return check(l + 1, r - 1) ? 3 : 0;
	return 3;
}

string read(){
	string s;
	getline(cin, s);
	string t = "";
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' ') continue;
		t += s[i];
	}
	return t;
}

int main(){
	int T;
	scanf("%d", &T);
	getline(cin, s);
	while (T--){
		cin >> buf;
		if (buf == "#") cin >> buf;
		string t; cin >> t;
		s = read();
		mp[t] = check(0, s.length() - 1);
	}
	s = read();
	if (check(0, s.length() - 1)) printf("OK\n");
	else printf("Suspicious\n");
	return 0;
}