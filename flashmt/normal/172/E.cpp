#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

char s[1000100],t[1000100];
int l,n,par[250500],ans,B;
long long name[250250],b[222];
vector <int> a[250500];


long long hash(string s)
{
	long long res=0;
	for (int i=0;i<int(s.size());i++) res=res*29+s[i]-'a'+1;
	return res;
}

void go(int i,int x)
{
	i++;
	if (i>=l) return;
	string cur="";
	while (i<l && s[i]!='>') 
	{
		if (s[i]!='<') cur+=s[i];
		i++;
	}
	if (cur[0]=='/') go(i,par[x]);
	else
		if (cur[cur.size()-1]=='/')
		{
			cur.erase(cur.size()-1,1);
			name[++n]=hash(cur); 
			a[x].push_back(n);
			par[n]=x; 
			go(i,x);
		}
		else
		{
			name[++n]=hash(cur); 
			a[x].push_back(n);
			par[n]=x; 
			go(i,n);
		}
}

void calc(int x,int par,int f)
{
	if (name[x]==b[B-1] && f==B-1) ans++;	
	else
		if (name[x]==b[f]) f++;
	for (int j=0;j<int(a[x].size());j++)
		calc(a[x][j],x,f);
}

int main()
{
	scanf("%s",s);
	l=strlen(s);
	go(0,0);
	int q;
	cin >> q;
	gets(t);
	while (q--)
	{
		long long cur=0;
		gets(t);
		int lt=strlen(t);
		B=0;
		for (int i=0;i<lt;i++)
			if (t[i]==' ') b[B++]=cur, cur=0;
			else cur=cur*29+t[i]-'a'+1;
		b[B++]=cur;
		ans=0;
		for (int i=0;i<int(a[0].size());i++) calc(a[0][i],0,0);
		cout << ans << endl;
	}
}