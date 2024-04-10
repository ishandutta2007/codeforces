#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string s,t;
	int dif=-1;
	cin >> s >> t;
	if (s.size()==t.size())
	{
		for (int i=0;i<s.size();i++) 
			if (s[i]!=t[i]) 
				if (dif==-1) dif=i;
				else
					if (dif>=0 && s[i]==t[dif] && t[i]==s[dif]) dif=-2;
					else
					{
						puts("NO"); 
						return 0;
					}
		if (dif<0) puts("YES");
		else puts("NO");
	}
	else puts("NO");
}