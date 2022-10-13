#include <bits/stdc++.h>
using namespace std;
const string POKEMONS[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int match(string s, string t)
{
	if (s.size() != t.size()) return 0;
	for (int i = 0; i < int(s.size()); i++)
		if (s[i] != '.' && s[i] != t[i])
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < 8; i++)
		if (match(s, POKEMONS[i]))
		{
			cout << POKEMONS[i] << endl;
			return 0;
		}
}