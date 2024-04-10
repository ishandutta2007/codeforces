#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}

char s[20001];
int p1,p2,len;
inline void gg(){puts("NO");exit(0);}
int main()
{
	scanf("\n%s",s+1);
	len=strlen(s+1);
	if(s[1]!='a')	gg();
	For(i,1,len)	if(s[i]=='b')	{p1=i;break;}
	For(i,1,len)	if(s[i]!='a')	{if(i!=p1)	gg();break;}
	if(!p1)	gg();
	For(i,p1,len)	if(s[i]=='c')	{p2=i-1;break;}
	if(!p2)	gg();

	if((len-p2)!=(p1-1)&&(len-p2)!=(p2-p1+1))	gg();

	For(i,1,p1-1)	if(s[i]!='a')	gg();
	For(i,p1,p2)	if(s[i]!='b')	gg();
	For(i,p2+1,len)	if(s[i]!='c')	gg();
	puts("YES");
}