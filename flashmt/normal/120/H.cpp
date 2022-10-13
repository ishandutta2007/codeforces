#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxR 27*27*27*27
using namespace std;

vector <int> a[222];
int n,l[maxR],r[222],pre[maxR];

void generate(int i,int pos,string s,int mask,int z)
{
	if (i==4)
	{
		a[z].push_back(mask);
		return;
	}
	for (int j=pos;j<s.size();j++) generate(i+1,j+1,s,mask*27+s[j]-'`',z);
}

int findRightMatch(int x)
{
	for (int i=0;i<int(a[x].size());i++)
	{
		int y=a[x][i];
		if (pre[y]>=0) continue;
		pre[y]=x;
		if (l[y]<0) return y;
		y=findRightMatch(l[y]);
		if (y>=0) return y;
	}
	return -1;
}

int findNewMatch()
{
	for (int i=0;i<maxR;i++) pre[i]=-1;
	for (int i=0;i<n;i++)
		if (r[i]<0)
		{
			int x=findRightMatch(i);
			if (x>=0) return x;
		}
	return -1;
}

int incMatch()
{
	int L,t,R=findNewMatch();
	if (R<0) return 0;
	while (R>=0)
	{
		L=pre[R]; t=r[L];
		r[L]=R; l[R]=L;
		R=t;
	}
	return 1;
}

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	string s;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> s;
		s="```"+s; 
		generate(0,0,s,0,i);
		sort(a[i].begin(),a[i].end());
		a[i].resize(unique(a[i].begin(),a[i].end())-a[i].begin());
		r[i]=-1;
	}
	for (int i=0;i<maxR;i++) l[i]=-1;
	for (int i=0;i<n;i++)
		if (!incMatch()) 
		{
			puts("-1");
			return 0;
		}
	for (int i=0;i<n;i++)
	{
		s="";
		while (r[i]) s=char(r[i]%27+96)+s, r[i]/=27;
		cout << s << endl;
	}
}