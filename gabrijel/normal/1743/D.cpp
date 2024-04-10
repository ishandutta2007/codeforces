#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

string s, rj;
vector <int> pos;
vector <string> potrj;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, pj = -1, pn = -1;
	cin >> n;
	cin >> s;
	REP(i, n) {
		if(s[i] == '0') {
			if(pj != -1) {
				if(pn == -1) pn = i;
				pos.push_back(i - pn);
			}
		}
		else {
			if(pj == -1) pj = i;
		}
	}
	if(pj == -1) {
		cout << "0\n";
		return 0;
	}
	else if(pn == -1) {
		for(int i = pj; i < n; i++) cout << "1";
		cout << "\n";
		return 0;
	}
	rj = "";
	for(int i = pj; i < n; i++) rj.push_back(s[i]);
	for(int i = pj; i < pn; i++) {
		potrj.push_back(rj);
		REP(j, (int)pos.size()) {
			if(s[i + pos[j]] == '1') potrj.back()[pn - pj + pos[j]] = '1';
		}
	}
	sort(potrj.begin(), potrj.end());
	cout << potrj.back() << "\n";
	return 0;
}