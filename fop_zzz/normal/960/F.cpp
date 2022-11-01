#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<map>
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

int n,m,ans,x,y,v;
map<int,int> tr[100001];
inline int Get(int x,int y)
{
	int tmp=0;
		for(int j=y;j;j-=j&-j)	if(tr[x].count(j))	tmp=max(tmp,tr[x][j]);
	return tmp;
}
inline void Add(int x,int y,int z)
{
	for(int j=y;j<=1000000;j+=j&-j)	tr[x][j]=max(tr[x][j],z);
}
int main()
{
	n=read();m=read();
	For(i,1,m)	
	{
		x=read();y=read();v=read()+1;
		int tmp=Get(x,v-1)+1;
		ans=max(ans,tmp);
		Add(y,v,tmp);
	}
	writeln(ans);
}