#include <iostream>
#include <stdio.h>
#include<string>
#include<map>
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
string S[300];
map<string,int> mp;
string cun[300][300];
int num[300],n,tot,now;
inline bool pd(int x,int y,int t)
{
	string ts=cun[t][x],ps=cun[t][y];
	int len1=ts.length(),len2=ps.length();
	if(len1<len2)	return 0;
	int tep=len1-1;
	for(int i=len2-1;i>=0;i--)
	{
		if(ps[i]!=ts[tep])	return 0;
		tep--;
	}
	return 1;
}
bool can[2001];
inline void solve(int x)
{
	int ans=num[x];
	for(int i=1;i<=num[x];++i)	can[i]=1;
	for(int i=1;i<=num[x];++i)
		if(can[i])
			for(int j=1;j<=num[x];++j)
			if(can[j])
			{
				if(i==j)	continue;
				if(pd(i,j,x))	can[j]=0,ans--;
			}
	cout<<S[x]<<' ';printf("%d ",ans);
//	For(i,1,num[x])	cout<<i<<"=>"<<can[i]<<endl;
	for(int i=1;i<=num[x];++i)	if(can[i])	cout<<cun[x][i]<<' ';
	cout<<endl;
}
string s;char c;int ent;
int main()
{
	n=read();
	while(1)
	{
		cin>>s;c=getchar();if(c=='\n')	ent++;
		if(!isdigit(s[0]))
		{
			if(!mp[s])	mp[s]=++tot;
			now=mp[s];
			S[now]=s;
			read();
		}
		else
			cun[now][++num[now]]=s;
		if(ent==n)	break;
		
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
		solve(i);
}