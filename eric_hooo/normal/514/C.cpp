#include<bits/stdc++.h>
using namespace std;
string s;
int siz,n,m,k;
int bor[1000000][26];
int bob[26000000];
void add(int v,int y)
{
	if(y==s.size())
	{
		bob[v]=1;
		return;
	}
	if(bor[v][s[y]-'a']!=0)
		add(bor[v][s[y]-'a'],y+1);
	else
	{
		siz++;
		bor[v][s[y]-'a']=siz;
		add(siz,y+1);
	}
}
void pos(int v,int y,int z)
{
	if(k==1)
		return;
	if(y==s.size())
	{
		if(bob[v]==1&&z==1)
		{
			k=1;
			return;
		}
	}
	if(bor[v][s[y]-'a']!=0)
		pos(bor[v][s[y]-'a'],y+1,z);
	if(z+k>0)
		return;
	for(char q='a';q<='z';q++)
	{
		if(q!=s[y]&&bor[v][q-'a']!=0)
			pos(bor[v][q-'a'],y+1,1);
		if(k>0)
			return;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	siz=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		add(1,0);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		k=0;
		pos(1,0,0);
		if(k==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}