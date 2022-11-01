#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read()
{
    int t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=(t<<1)+(t<<3)+c-48,c=getchar();
    return t*f;
}
int mp[20001],ans1,ans2;
char s[201];
int main()  
{  
	mp['Q']=9;mp['R']=5;mp['B']=3;mp['N']=3;mp['P']=1;
	For(i,1,8)
	{
		scanf("\n%s",s+1);
		For(j,1,8)	if(s[j]!='.')	
		{
			if(isupper(s[j]))	ans1+=mp[s[j]];
			else	ans2+=mp[s[j]+'A'-'a'];
		}
	}
	if(ans1>ans2)	puts("White");else if(ans1<ans2)	puts("Black");	else puts("Draw");
}