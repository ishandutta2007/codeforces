#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=100;
#endif

string s, t;
int ch[30], ch2[30];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> s >> t;
	for (int i=0; i<s.length(); i++) ch[s[i]-'a']++;
	for (int i=0; i<t.length(); i++) ch2[t[i]-'a']++;
	bool a=true;
	for (int i=0; i<30; i++) if (ch[i]!=ch2[i]) a=false;
	if (a) {
		cout << "array";
		return 0;
	}
	a=true;
	for (int i=0, j=0; j<t.length(); j++) {
		while (i<s.length()&&s[i]!=t[j])
			i++;
		if (i==s.length()) a=false;
		i++;
	}
	if (a) {
		cout << "automaton";
		return 0;
	}
	a=true;
	for (int i=0; i<30; i++) if (ch[i]<ch2[i]) a=false;
	if (a) {
		cout << "both";
		return 0;
	}
	cout << "need tree";
    return 0;
}