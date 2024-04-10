#include<iostream>
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
using namespace std;
int n,a[200001],len,q[200001];
bool vis[11],flag;
char s[200001];
inline void out()
{
	int tep=len;while(q[tep]==0)	tep--;
	Dow(i,1,tep)	putchar(q[i]+'0');flag=1;
	puts("");
}
inline void Dfs(int pos,int num,int zero,int lim)
{
	if(flag)	return; 
	if(pos==0&&num==0)	{out();return;}
	if(pos==0)	return;
	if(pos<num)	return;
	int tp=lim?a[pos]:9;
	Dow(i,0,tp)
	{
		if(zero&&i==0)	{q[pos]=0;Dfs(pos-1,num,1,lim&&i==a[pos]);continue;}
		
		if(vis[i])
		{
			vis[i]=0;q[pos]=i;
			Dfs(pos-1,num-1,0,lim&&i==a[pos]);
			vis[i]=1;
		}
		else
		{
			vis[i]=1;q[pos]=i;
			Dfs(pos-1,num+1,0,lim&&i==a[pos]);
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	For(T,1,n)
	{
		scanf("\n%s",s+1);
		len=strlen(s+1);
		For(i,1,len)	a[i]=s[len-i+1]-'0';
		a[1]--;
		For(i,1,len)	if(a[i]<0)	a[i]+=10,a[i+1]--;
		if(!a[len])len--;
		if(len&1)	{For(i,1,len-1)	putchar('9');puts("");continue;}
		Dfs(len,0,1,1);
		flag=0;
	}
}