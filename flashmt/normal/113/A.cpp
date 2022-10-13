#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};
			string t[]={"lios","liala","etr","etra","initis","inites"};

char s[100100];

int main()
{
	//freopen("a.in.3","r",stdin);
	int senGen=-1,word=0,state=0,re=1;
	while (scanf("%s",&s)==1)
	{
		int i,type=0,gender=0;
		for (i=0;i<6;i++)
		{
			int l=strlen(s),k=t[i].length();
			if (l<k) continue;
			int ok=1;
			for (int j=1;j<=k;j++)
				if (s[l-j]!=t[i][k-j])
				{
					ok=0; break;
				}
			if (ok) break;
		}
		if (i>=6)
		{
			puts("NO"); return 0;
		}
		type=i>>1; gender=i&1;
		word++;
		//cout << type << " " << gender << endl;
		if (senGen<0) senGen=gender;
		else
			if (senGen!=gender)
			{
				puts("NO"); return 0;
			}
		if (!type)
		{
			if (state) re=0;
		}
		else
			if (type==1)
			{
				if (!state) state=1;
				else re=0;
			}
			else
			{
				if (!state) re=0;
				else
					if (state==1) state=2;
			}
		//cout << state << endl;
	}
	if (!state) re=0;
	if (re || word==1) puts("YES");
	else puts("NO");
	return 0;
}