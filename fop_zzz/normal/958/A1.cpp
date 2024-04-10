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

int a[201][201],b[201][201],c[201][201],n;
char s[201][201];
inline void check()
{
	For(i,1,n)	For(j,1,n)	if(a[i][j]!=b[i][j])	return;
	puts("Yes");
	exit(0);
}
inline void check1()
{
	For(i,1,n)	For(j,1,n)	if(a[n-i+1][j]!=b[i][j])	return;
	puts("Yes");
	exit(0);
}
inline void check2()
{
	For(i,1,n)	For(j,1,n)	if(a[i][n-j+1]!=b[i][j])	return;
	puts("Yes");
	exit(0);
}
int main()
{
	n=read();
	For(i,1,n)	
		scanf("\n%s",s[i]+1);
	For(i,1,n)	For(j,1,n)
	{
		a[i][j]=(s[i][j]=='X');
	}
	For(i,1,n)	
		scanf("\n%s",s[i]+1);
	For(i,1,n)	For(j,1,n)
	{
		b[i][j]=(s[i][j]=='X');
	}

	check();
	check1();
	check2();
	For(i,1,n)	For(j,1,n)
	{
		int tj=i,ti=n-j+1;
		c[ti][tj]=a[i][j];
	}
	For(i,1,n)	For(j,1,n)	a[i][j]=c[i][j];

	check();
	check1();
	check2();
	For(i,1,n)	For(j,1,n)
	{
		int tj=i,ti=n-j+1;
		c[ti][tj]=a[i][j];
	}
	For(i,1,n)	For(j,1,n)	a[i][j]=c[i][j];
	
	check();
	check1();
	check2();
	For(i,1,n)	For(j,1,n)
	{
		int tj=i,ti=n-j+1;
		c[ti][tj]=a[i][j];
	}
	For(i,1,n)	For(j,1,n)	a[i][j]=c[i][j];
	
	check();
	check1();
	check2();
	puts("No");
}