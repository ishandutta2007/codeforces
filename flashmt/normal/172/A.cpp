#include <iostream>
#include <string>
using namespace std;

string s[30000];

int main()
{
	int n,j;
	cin >> n;
	for (int i=0;i<n;i++) cin >> s[i];
	for (j=0;j<s[0].size();j++)
	{
		int ok=1;
		for (int i=1;i<n;i++)
			if (s[i][j]!=s[i-1][j]) ok=0;
		if (!ok) break;
	}
	cout << j << endl;
}