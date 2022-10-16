/*input
2 2
1 2
1 1
1
*/
#include <bits/stdc++.h>

using namespace std;

vector<int>grarev[100000];
vector<int>gra[100000];

bool laim[100000];
bool pralaim[100000];
int laimf[100000];
int pralaimf[100000];
int isein[100000];

void dfs(int d) {
	//cout << d << " " << pralaim[d] << " " << laim[d] << endl;

	for (auto && x : grarev[d]) {
		if (pralaim[d] and !laim[x]) {
			laim[x] = true;
			laimf[x] = d;
			dfs(x);
		}

		if (laim[d] and !pralaim[x]) {
			pralaim[x] = true;
			pralaimf[x] = d;
			dfs(x);
		}
	}
}

bool apl[100000];
bool dabar[100000];
bool cycl(int d) {
	if (!apl[d]) {
		apl[d] = true;
		dabar[d] = true;

		for (auto && x : gra[d]) {
			if (!apl[x] and cycl(x))
				return true;
			else if (dabar[x])
				return true;
		}
	}

	dabar[d] = false;
	return false;
}
vector<int>ats;
void kelias(int d, bool b) {
	if (b) {
		ats.push_back(laimf[d]);
		kelias(laimf[d], !b);
	}
	else {
		if (isein[d] != 0) {
			ats.push_back(pralaimf[d]);
			kelias(pralaimf[d], !b);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;

		while (c--) {
			int x;
			cin >> x;
			x--;
			grarev[x].push_back(i);
			gra[i].push_back(x);
			isein[i]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (isein[i] == 0) {
			pralaim[i] = true;
			dfs(i);
		}
	}

	int s;
	cin >> s;
	s--;

	if (!laim[s] and !pralaim[s]) {
		cout << "Draw";
	}

	if (laim[s]) {
		kelias(s, true);
		cout << "Win\n";

		cout << s + 1 << " ";

		for (auto && x : ats) {
			cout << x + 1 << " ";
		}

		return 0;
	}

	if (pralaim[s]) {
		if (cycl(s)) {
			cout << "Draw";
		}
		else {
			cout << "Lose";
		}

		return 0;
	}

	return 0;
}