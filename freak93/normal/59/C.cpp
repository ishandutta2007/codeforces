#include <iostream>
#include <string>

using namespace std;

int n, i, k;
string s;
int mark[500], ps[500], pd[500];

int main() {
	cin >> n;
	cin >> s;
	for (i = 0; i < (s.size() + 1) / 2; ++i)
		if (s[i] == '?' && s[s.size() - i - 1] != '?')
			s[i] = s[s.size() - i - 1], mark[s[i]] = 1;
		else
			if (s[i] != '?' && s[s.size() - i - 1] == '?')
				s[s.size() - i - 1] = s[i], mark[s[i]] = 1;
			else
				if (s[i] != s[s.size() - i - 1]) {
					cout << "IMPOSSIBLE";
					return 0;
				}
				else
					if (s[i] =='?')
						ps[++k] = i, pd[k] = s.size() - i - 1;
					else
						mark[s[i]] = 1;;
	for (i = 'a' + n - 1; i >= 'a'; --i)
		if (mark[i] == 0 && k == 0) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		else
			if (mark[i] == 0) {
				s[ps[k]] = i, s[pd[k]] = i;
				--k;
			} 
	while (k > 0)
		s[ps[k]] = s[pd[k]] = 'a', --k;

	cout << s;
}