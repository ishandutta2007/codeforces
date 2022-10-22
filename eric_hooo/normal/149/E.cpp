#include <bits/stdc++.h>
using namespace std;

char buf[100010];
int fail[1010], p1[100010], p2[100010];

string read(){scanf("%s", buf); return buf;}

void getfail(string &s){
	int n = s.length();
	fail[0] = -1;
	int j = -1;
	for (int i = 1; i <= n; i++){
		while (~j && s[j] != s[i - 1]) j = fail[j];
		fail[i] = ++j;
		if (i != n && s[i] == s[fail[i]] && ~fail[fail[i]]) fail[i] = fail[fail[i]];
	}
}

void match(string &s, string &t, int *p){
	int m = t.size(), n = s.size(), j = 0;
	for (int i = 0; i < m; i++){
		while (~j && t[i] != s[j]) j = fail[j];
		j++, p[i] = j;
		if (i) p[i] = max(p[i], p[i - 1]);
	}
}

int main(){
	string t = read();
	int n = t.size(), m;
	scanf("%d", &m);
	int ans = 0;
	for (int i = 0; i < m; i++){
		string s = read();
		getfail(s), match(s, t, p1);
		reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
		getfail(s), match(s, t, p2);
		reverse(p2, p2 + n), reverse(t.begin(), t.end());
		int maxj = 0;
		for (int j = 1; j < n; j++){
			maxj = max(maxj, p1[j - 1] + p2[j]);
		}
//		cout << "  maxj:" << maxj << endl;
		ans += maxj >= s.size() && s.size() > 1;
	}
	printf("%d\n", ans);
	return 0;
}