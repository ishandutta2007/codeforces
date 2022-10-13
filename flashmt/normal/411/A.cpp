#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int mask = 0;
	for (int i = 0; i < int(s.size()); i++)
		if (s[i] >= '0' && s[i] <= '9') mask |= 1;
		else if (s[i] >= 'a' && s[i] <= 'z') mask |= 2;
		else if (s[i] >= 'A' && s[i] <= 'Z') mask |= 4;
	
	cout << (mask == 7 && s.size() >= 5 ? "Correct" : "Too weak");
}