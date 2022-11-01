#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<ll,ll>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int n,mx,lres,rres;
int lef=1;
char s[10001][1100];
int main()
{
	n=1;
	while(cin.getline(s[n],1000))	n++;
	n--;
	For(i,1,n)	mx=max(mx,(int)strlen(s[i]));
	For(i,1,mx+2)	putchar('*');puts("");
	For(i,1,n)
	{
		int len=strlen(s[i]);
		lres=(mx-len)/2;rres=mx-len-lres;
		if(lres!=rres)	if(!lef)	swap(lres,rres),lef=1;else lef=0;
		putchar('*');For(j,1,lres)	putchar(' ');
		For(j,0,len-1)	putchar(s[i][j]);
		For(j,1,rres)	putchar(' ');
		puts("*");
	}	
	For(i,1,mx+2)	putchar('*');puts("");
}