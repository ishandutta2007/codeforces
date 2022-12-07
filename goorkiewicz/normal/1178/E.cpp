#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j;
char s [1000002];
int o1 [1001];
int o2 [1001];
vector <char> out1, out2;

void check ()
	{
	i = 0;
	j = n+1;
	o1['a'] = 0;
	o1['b'] = 0;
	o1['c'] = 0;
	o2['a'] = 0;
	o2['b'] = 0;
	o2['c'] = 0;
	while (i<j)
		{
		i++;
		if (i==j)
			break;
		if (o1[s[i]]==0)
			o1[s[i]] = i;
		if (o2[s[i]]!=0)
			{
			out1.push_back(s[i]);
			out2.push_back(s[i]);
			i = o1[s[i]];
			j = o2[s[i]];
			o1['a'] = 0;
			o1['b'] = 0;
			o1['c'] = 0;
			o2['a'] = 0;
			o2['b'] = 0;
			o2['c'] = 0;
			continue;
			}
		j--;
		if (i==j)
			break;
		if (o2[s[j]]==0)
			o2[s[j]] = j;
		if (o1[s[j]]!=0)
			{
			out1.push_back(s[j]);
			out2.push_back(s[j]);
			i = o1[s[j]];
			j = o2[s[j]];
			o1['a'] = 0;
			o1['b'] = 0;
			o1['c'] = 0;
			o2['a'] = 0;
			o2['b'] = 0;
			o2['c'] = 0;
			continue;
			}
		}
	if (o1['a']!=0 || o2['a']!=0)
		out1.push_back('a');
	else if (o1['b']!=0 || o2['b']!=0)
		out1.push_back('b');
	else if (o1['c']!=0 || o2['c']!=0)
		out1.push_back('c');
	}

void answer (void)
	{
	reverse(out2.begin(), out2.end());
	for (char c : out1)
		printf ("%c",c);
	for (char c : out2)
		printf ("%c",c);
	printf ("\n");
	exit(0);
	}

int main ()
	{
	scanf ("%s",s+1);
	n = strlen(s+1);
	
	check();
	answer();
	return 0;
	}