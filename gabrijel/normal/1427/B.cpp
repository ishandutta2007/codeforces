#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int br_w = 0, duljina_rupe = 0;;
		bool zad_w = 0, imao_w = 0;
		int rj = 0;
		vector <int> rupe;
		REP(i, n) {
			if(s[i] == 'W') {
				br_w++;
				if(zad_w) rj += 2;
				else rj++;
				zad_w = 1;
				if(imao_w && duljina_rupe) rupe.push_back(duljina_rupe);
				duljina_rupe = 0;
				imao_w = 1;
			}
			else {
				duljina_rupe++;
				zad_w = 0;
			}
		}
		sort(rupe.begin(), rupe.end());
		int poc = 0, kraj = 0;
		int ptr = 0;
		while(ptr < n && s[ptr] == 'L') {
			poc++;
			ptr++;
		}
		ptr = n - 1;
		while(ptr >= 0 && s[ptr] == 'L') {
			kraj++;
			ptr--;
		}
		if(br_w == 0) {
			if(k) cout << k * 2 - 1 << "\n";
			else cout << 0 << "\n";
		}
		else {
			ptr = 0;
			while(ptr < (int)rupe.size() && k) {
				if(rupe[ptr] == 1) rj += 3;
				else rj += 2;
				rupe[ptr]--;
				if(!rupe[ptr]) ptr++;
				k--;
			}
			rj += 2 * min(k, poc);
			k = max(0, k - poc);
			rj += 2 * min(k, kraj);
			cout << rj << "\n";
		}
	}
	return 0;
}