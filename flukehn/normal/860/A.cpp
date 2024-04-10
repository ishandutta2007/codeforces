#include<bits/stdc++.h>
using namespace std;
string s;
bool v[56415];
int main()
{
	v['a']=v['e']=v['i']=v['o']=v['u']=1;
	cin>>s;
	int g=0,h=0;
	for(int i=0;i<s.size();++i)
	{
		if(v[s[i]])
		{
			putchar(s[i]);
			g=h=0; continue;
		}
		if(g==0) h=s[i];
		else if(s[i]!=h) h=0;
		++g;
		if(g>=3&&!h)
		{
			putchar(' '); g=h=0;
			++g; h=s[i];
		}
		putchar(s[i]);
	}
}