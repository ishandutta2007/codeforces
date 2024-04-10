#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
string S;
string T;
int Q;
int pres[MAXN][2], pret[MAXN][2];
int as[MAXN], at[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> S >> T >> Q;

	for (int i = 0; i < S.size(); i++) {
		pres[i + 1][S[i] != 'A']++;
	}
	for (int i = 0; i < T.size(); i++) {
		pret[i + 1][T[i] != 'A']++;
	}

	for (int i = 1; i <= S.size(); i++) {
		pres[i][0] += pres[i - 1][0];
		pres[i][1] += pres[i - 1][1];
	}
	for (int i = 1; i <= T.size(); i++) {
		pret[i][0] += pret[i - 1][0];
		pret[i][1] += pret[i - 1][1];
	}

	as[0] = S[0] == 'A';
	at[0] = T[0] == 'A';
	for (int i = 1; i < S.size(); i++)
		as[i] = S[i] == 'A' ? as[i - 1] + 1 : 0;
	for (int i = 1; i < T.size(); i++)
		at[i] = T[i] == 'A' ? at[i - 1] + 1 : 0;

	while (Q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; c--; b--; d--;
		int sn = pres[b + 1][1] - pres[a][1];
		int tn = pret[d + 1][1] - pret[c][1];

		bool ok = true;
		if (sn % 2 != tn % 2)
			ok = false;
		else if (sn > tn)
			ok = false;
		else {
			int sa = min(as[b], b - a + 1);
			int ta = min(at[d], d - c + 1);
			if (ta == 0) {
				// "good" case
				if (sa % 3 != 0)
					sn += 2;
				if (sn > tn)
					ok = false;
			}
			else {
				// annoying case, t ends in 'A'
				if (ta > sa)
					ok = false;
				else {
					sa -= ta;
					if (sa == 0 && sn == 0 && tn != 0) {
						ok = false;
					}
					else {
						if (sa % 3 != 0)
							sn += 2;
						if (sn > tn)
							ok = false;
					}
				}
			}
		}

		cout << ok;
	}

	cout << endl;
	return 0;
}