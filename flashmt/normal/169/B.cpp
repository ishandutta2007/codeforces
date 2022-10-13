#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s,t;
int d[10];

int main()
{
	cin >> s >> t;
	for (int i=0;i<int(t.size());i++) d[t[i]-'0']++;
	for (int i=0,j=9;i<int(s.size()) && j;i++)
	{
		while (j && !d[j]) j--;
		if (s[i]-'0'<j) s[i]=char(j+'0'), d[j]--;
	}
	cout << s << endl;
}