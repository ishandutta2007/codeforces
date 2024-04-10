#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <sstream>
#include <queue>
#include <vector>
#define N 1000100
using namespace std;

int n,q,t=1,included[N],pos[N],discover[N],finish[N],step,f[N];
int tNext[N][26],tVal[N],tSuffix[N];
vector <int> a[N];
string name[100100];

int addTrie(string name)
{
	int x=1;
	for (int i=0;i<int(name.size());i++)
	{
		int ch=name[i]-'a';
		if (!tNext[x][ch]) tNext[x][ch]=++t;
		x=tNext[x][ch];
	}
	return x;
}

void buildAC()
{
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		for (int i=0;i<26;i++)
		{
			int y=tNext[x][i];
			if (y)
			{
				int s=tSuffix[x];
				while (s && !tNext[s][i]) s=tSuffix[s];
				tSuffix[y]=(s?tNext[s][i]:1);
				a[tSuffix[y]].push_back(y);
				q.push(y);
			}
		}
	}
}

void visit(int x)
{
	discover[x]=++step;
	for (int i=0;i<int(a[x].size());i++) visit(a[x][i]);
	finish[x]=step;
}

void addFenwick(int x,int v)
{
	while (x<=t) f[x]+=v, x+=x&-x;
}

int getFenwick(int x)
{
	int res=0;
	while (x) res+=f[x], x-=x&-x;
	return res;
}

long long match(string s)
{
	long long res=0;
	int x=1;
	for (int i=0;i<int(s.size());i++)
	{
		int ch=s[i]-'a';
		while (x>1 && !tNext[x][ch]) x=tSuffix[x];
		x=max(tNext[x][ch],1);
		if (x>1) res+=getFenwick(discover[x]);
	}
	return res;
}

int main()
{
	cin >> q >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> name[i];
		pos[i]=addTrie(name[i]);
		included[i]=1;
	}
	buildAC();
	visit(1);
	for (int i=1;i<=n;i++) 
	{
		addFenwick(discover[pos[i]],1);
		addFenwick(finish[pos[i]]+1,-1);
	}
	
	while (q--)
	{
		string s;
		cin >> s;
		char type=s[0];
		s.erase(0,1);
		
		if (type=='?') cout << match(s) << endl;
		else
		{
			int x;
			stringstream ss(s);
			ss >> x;
			
			if (type=='+' && !included[x])
			{
				addFenwick(discover[pos[x]],1);
				addFenwick(finish[pos[x]]+1,-1);
				included[x]=1;
			}
			
			if (type=='-' && included[x])
			{
				addFenwick(discover[pos[x]],-1);
				addFenwick(finish[pos[x]]+1,1);
				included[x]=0;
			}
		}
	}
}