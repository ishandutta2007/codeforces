#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;
map < string, int > cnt;
map < string, string > f;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		set < string > difs;
		for (int j = 0; j < s.size(); j++) {
			string aux = "";
			for (int k = j; k < s.size(); k++) {
				aux += s[k];
				difs.insert(aux);
			}
		}
		for (string aux : difs) {
			cnt[aux]++;
			f[aux] = s;
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		cin >> s;
		int x = cnt[s];
		if (x == 0) printf("0 -\n");
		else printf("%d %s\n", x, f[s].c_str());
	}
	return 0;
}