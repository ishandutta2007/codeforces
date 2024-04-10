#include <bits/stdc++.h>
using namespace std;

int canRemove(string s, string t)
{
	int i = 0, j = 0;
	while (i < int(s.size()) && j < int(t.size()))
	{
		if (s[i] == t[j]) j++;
		i++;
	}
	return j == t.size();
}

int canSwap(string s, string t)
{
	int cntS[256] = {0}, cntT[256] = {0};
	for (int i = 0; i < int(s.size()); i++) cntS[s[i]]++;
	for (int i = 0; i < int(t.size()); i++) cntT[t[i]]++;
	for (char c = 'a'; c <= 'z'; c++)
		if (cntS[c] != cntT[c])
			return 0;
	return 1;
}

int canRemoveAndSwap(string s, string t)
{
	int cntS[256] = {0}, cntT[256] = {0};
	for (int i = 0; i < int(s.size()); i++) cntS[s[i]]++;
	for (int i = 0; i < int(t.size()); i++) cntT[t[i]]++;
	for (char c = 'a'; c <= 'z'; c++)
		if (cntS[c] < cntT[c])
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	if (canRemove(s, t)) cout << "automaton" << endl;
	else if (canSwap(s, t)) cout << "array" << endl;
	else if (canRemoveAndSwap(s, t)) cout << "both" << endl;
	else cout << "need tree" << endl;		
}