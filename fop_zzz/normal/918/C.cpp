#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int len,ans;
char s[20001];
int main()
{
	scanf("\n%s",s+1);
	len=strlen(s+1);
	For(i,1,len)
	{
		int z=0,can=0;
		For(j,i,len)
		{
			if(s[j]=='?')	can++,z--;
			if(s[j]=='(')	z++;
			if(s[j]==')')	z--;
			if(z<0&&can>0)	can--,z+=2;
			if(z<0&&can<=0)	break;
			if(z==0)	ans++;
		}
	}
	cout<<ans<<endl;
}