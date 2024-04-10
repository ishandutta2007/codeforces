#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 100005;

int n, k, i, j, start[250];
long long rez;

string s;
vector<int> E[maxn];

int main() {
	cin >> k >> n;
	cin >> s;
	for (i = 0; i < static_cast<int>(s.size()); ++i)
		E[static_cast<int>(s[i])].push_back(i);
	
	for (i = 'a'; i <= 'z'; ++i)
		E[i].push_back(maxn * 2);
	for (i = 1; i <= k; ++i) {
		cin >> s;
		rez = 0;
		for (j = 'a'; j <= 'z'; ++j)
			start[j] = 0;
		for (j = 0; j < static_cast<int>(s.size()); ++j) {
			while (E[static_cast<int>(s[j])][start[static_cast<int>(s[j])]] <= j)
				++start[static_cast<int>(s[j])];
			if (E[s[j]].size() == 1) {
				rez += s.size();
				continue;
			}
			if (start[s[j]] > 0)
                rez += min(j - E[s[j]][start[s[j]] - 1], E[s[j]][start[s[j]]] - j);
			else
				rez += E[s[j]][start[s[j]]] - j;
		}

		cout << rez << "\n";
	}
}