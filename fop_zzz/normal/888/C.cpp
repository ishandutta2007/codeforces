#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
char s[200001];
int len,mi[2001],las[2001];
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	For(i,'a','z')	mi[i]=0;
	For(i,1,len)
	{
		if(!las[s[i]])	las[s[i]]=i,mi[s[i]]=i;
		else	mi[s[i]]=max(mi[s[i]],i-las[s[i]]),las[s[i]]=i;
	}
	For(i,'a','z')	if(mi[i])	mi[i]=max(mi[i],len-las[i]+1);
	int ans=1e9;
	For(i,'a','z')	if(mi[i])	ans=min(ans,mi[i]);//cout<<mi[i]<<' '<<(char)i<<endl;
	cout<<ans<<endl;
}