#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string a[150];
map <string, int> K;
vector<string> res[150];

int t[150], p[150];
int S, s[150];
pair<int, string> b[3][1005];
int Nt[3];

int best[3];
string bestn[3];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
    	cin >> a[i];
		string type; cin >> type;
		if (type == "weapon")
			t[i] = 0;
		else
			if (type == "orb")
				t[i] = 2;
			else
				t[i] = 1;

		int A[3]; cin >> A[0] >> A[1] >> A[2] >> s[i];
		p[i] = A[t[i]];

		S += s[i];
		K[a[i]] = i;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string name, type, weapon;
		int power;
		cin >> name >> type >> power >> weapon;
		int number = 0;
		if (type == "sentry")
			number = 1;
		else
			if (type == "physician")
				number = 2;
		if (M == S) {
			if (t[K[weapon]] == number)
				p[K[weapon]] += power;
			res[K[weapon]].push_back(name);
		}

		b[number][++Nt[number]] = make_pair(power, name);
	}

	for (int i = 0; i < 3; ++i)
		sort(b[i] + 1, b[i] + Nt[i] + 1);

	best[0] = best[1] = best[2] = -1;
	if (M == S) {
    	for (int i = 0; i < N; ++i)
			if (best[t[i]] < p[i])
				best[t[i]] = p[i], bestn[t[i]] = a[i];

		for (int i = 0; i < 3; ++i) {
			cout << bestn[i] << " ";
			cout << res[K[bestn[i]]].size() << " ";
			for (vector<string>::iterator it = res[K[bestn[i]]].begin(); it != res[K[bestn[i]]].end(); ++it)
				cout << *it << " ";
			cout << "\n";
		}
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j)
			if (t[j] == i) {
				int temp = p[j];
				for (int k = Nt[i]; k > 0 && k > Nt[i] - s[j]; --k)
					temp += b[i][k].first;
				if (temp > best[i])
					best[i] = temp, bestn[i] = a[j];
			}

		int who = K[bestn[i]];
		while (Nt[i] > 0 && s[who] > 0)
			res[who].push_back(b[i][Nt[i]--].second), --s[who];
	}

	for (int i = 0; i < 3; ++i) {
		int who = K[bestn[i]];
		while (s[who] > 0) {
			if (Nt[0] == 0 && Nt[1] == 0 && Nt[2] == 0)
				break;
			for (int j = 0; j < 3; ++j)
				if (Nt[j] > 0) {
					res[who].push_back(b[j][Nt[j]--].second);
					break;
			}
			--s[who];
		}
	}

	for (int i = 0; i < 3; ++i) {
		cout << bestn[i] << " ";
		cout << res[K[bestn[i]]].size() << " ";
		for (vector<string>::iterator it = res[K[bestn[i]]].begin(); it != res[K[bestn[i]]].end(); ++it)
			cout << *it << " ";
		cout << "\n";
	}
	return 0;
}