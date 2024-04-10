#include<cstdio>
#include<iostream>
#include<string>
const int MAXL = 5e3 + 5;
const int inf = 0x3fffffff;
using namespace std;

inline int min(int a,int b){ return a<b? a: b;}

string s1,s2,s;
int z[MAXL*3];

inline void calc_z(void)
{
	int l=0, r=0;
	for(int i=1; i<(int)s.size(); ++i)
	{
		z[i]=0;
		if(i<r) z[i] = min(r-i, z[i-l]);
		while(r<(int)s.size() && s[z[i]] == s[i+z[i]]) ++z[i];
		if(i+z[i] > r) l=i, r=i+z[i];
	}
}

int main(void)
{
	cin>>s1>>s2;
	
	int ans = inf;
	for(int i=0; i<(int)s1.size(); ++i)
	{
		s = s1.substr(i,s1.size()-i) + '#' + s1 + '$' + s2;
		calc_z();
		z[s1.size()+1] = 0;
		
		int tmp=0, tmp2=0;
		bool flag=0;
		int pos = -1;
		for(int j=1; j<(int)s.size(); ++j)
		{
			if(z[j] > tmp)
			{
				tmp2=tmp;
				tmp=z[j];
				pos=j;
				flag=1;
			}
			else if(z[j]==tmp) flag=0;
			else if(z[j] > tmp2) tmp2=z[j];
		}
		if(flag && pos > 2*(int)s1.size() - i + 1)
			ans = min(ans, tmp2+1);
	}
	
	if(ans==inf) printf("-1");
	else printf("%d",ans);
	return 0;
}