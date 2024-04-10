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
int n,ok,no;
char s[20001];
int main()
{
	n=read();
	scanf("\n%s",s+1);
	if(s[1]=='?'||s[n]=='?')	ok=1;
	For(i,2,n)	
		if(s[i]!='?')	if(s[i]==s[i-1])	no=1;
	For(i,2,n)	if(s[i]=='?')	if(s[i]==s[i-1])	ok=1;
	For(i,2,n-1)	if(s[i]=='?')	if(s[i-1]==s[i+1])	ok=1;
	if((!no)&&ok)	puts("Yes");else	puts("No");
}