#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a;
int n;

void calc(int res[],string s)
{
	int i=0,z=1;
	for (int i=0;i<10;i++) res[i]=0;
	while (s!="" && i>=0 && i<s.size())
	{
		int last=i;
		if (s[last]=='<' || s[last]=='>') 
		{
			z=(s[last]=='<'?-1:1);
			i+=z;
			if (s[i]=='<' || s[i]=='>') 
			{
				s.erase(last,1);
				if (last<i) i--;
			}
		}
		else 
		{
			i+=z;
			res[s[last]-'0']++;
			if (--s[last]<'0') 
			{
				s.erase(last,1);
				if (last<i) i--;
			}
		}		
	}
}

int main()
{
	int q,l,r;
	cin >> n >> q >> a;
	while (q--) 
	{
		cin >> l >> r; 
		int res[10];
		calc(res,a.substr(l-1,r-l+1));
		for (int i=0;i<10;i++) cout << res[i] << (i<9?' ':'\n');
	}
}