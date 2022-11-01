#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int top,ans=233,q[2001],ansq[201],n;
vector<int> vec;
inline void check()
{
	if(top<ans)
	{
		ans=top;
		For(i,1,ans)	ansq[i]=(q[i]<0?-1:1)*(1<<abs(q[i])-1);
	}
}
inline void Dfs(int x,vector<int> vec)
{
	if(x==22||vec.empty())	{check();return;}
	if(top>ans)	return;
	int siz=(int)vec.size();

	bool flag=0;
	For(i,0,siz-1)
		if(abs(vec[i])&1)	flag=1;	
	vector<int> tmp;
	if(!flag)
	{	
		For(i,0,siz-1)	if(vec[i]/2)	tmp.pb(vec[i]/2);
		Dfs(x+1,tmp);
		return;
	}
	tmp.clear();
	For(i,0,siz-1)
		if(((vec[i]+(abs(vec[i])&1)))/2!=0)	
			if(i==0||((vec[i]+(abs(vec[i])&1)))/2!=((vec[i-1]+(abs(vec[i-1])&1)))/2) tmp.pb(((vec[i]+(abs(vec[i])&1)))/2);
	q[++top]=-x;
	Dfs(x+1,tmp);
	top--;
	
	tmp.clear();
	For(i,0,siz-1)
		if(((vec[i]-(abs(vec[i])&1)))/2!=0)	
			if(i==0||((vec[i]-(abs(vec[i])&1)))/2!=((vec[i-1]-(abs(vec[i-1])&1)))/2)	tmp.pb(((vec[i]-(abs(vec[i])&1)))/2);
	q[++top]=x;
	Dfs(x+1,tmp);
	top--;

	
}
int main()
{
	n=read();
	For(i,1,n)	vec.pb(read());
	sort(vec.begin(),vec.end());
	Dfs(1,vec);
	writeln(ans);
	For(i,1,ans)	write_p(ansq[i]);
}