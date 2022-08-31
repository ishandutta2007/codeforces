#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	string s;
	vector<string> refs;
	vector<string> biblio;
	map<string, string> M;
	while (getline(cin, s)) {
		bool inside = false;
		bool cite = false;
		string current;
		if (s.find("{thebibliography") != string::npos) {
			continue;
		}
		for (int i = 0; i < (int)s.length(); ++i) {
			if (s[i] == '{') {
				if (s[i - 1] == 'e') {
					cite = true;
				} else {
					cite = false;
				}
				current = "";
				inside = true;
			} else if (s[i] == '}') {
				if (cite) {
					refs.push_back(current);
				} else {
					biblio.push_back(current);
					M[current] = s;
				}
				inside = false;
			} else if (inside) {
				current += s[i];
			}
		}
	}

	if (refs == biblio) {
		cout << "Correct\n";
	} else {
		cout << "Incorrect\n";
		cout << "\\begin{thebibliography}{99}\n";
		for (auto s : refs) {
			cout << M[s] << "\n";
		}
		cout << "\\end{thebibliography}\n";
	}

	return 0;
}