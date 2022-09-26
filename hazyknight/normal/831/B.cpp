#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

string s1,s2,text;

char match[130];

int main()
{
	cin >> s1 >> s2;
	for (int i = 0;i < s1.size();i++)
		match[s1[i]] = s2[i],match[s1[i] - 32] = s2[i] - 32;
	cin >> text;
	for (int i = 0;i < text.size();i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
			cout << text[i];
		else
			cout << char(match[text[i]]);
	}
	cout << endl;
	return 0;
}