#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll rj = 0;
	ll tr_rj = 0;
	int cnt = 0;
	vector <int> zad(n, -1);
	REP(i, n) {
		if(s[i] == '0') {
			REP(j, cnt) zad[j] = i - 1 - j;
			cnt = 0;
		}
		else {
			cnt++;
			tr_rj += (i - cnt - zad[cnt - 1]) + cnt;
		}
		rj += tr_rj;
	}
	cout << rj << "\n";
	return 0;
}