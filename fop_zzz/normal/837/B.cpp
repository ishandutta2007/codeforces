#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
int lx[2001],rx[2001],ly[2001],ry[2001],cnt[2001],n,m;
char s[2001];
int main()
{
	n=read();m=read();
	lx['R']=lx['G']=lx['B']=ly['R']=ly['G']=ly['B']=1e9;
	For(i,1,n)
	{
		scanf("%s",s+1);
		For(j,1,m)
		{
			lx[s[j]]=min(lx[s[j]],i);
			rx[s[j]]=max(rx[s[j]],i);
			ly[s[j]]=min(ly[s[j]],j);
			ry[s[j]]=max(ry[s[j]],j);
			cnt[s[j]]++;
		}
	}
	bool flag=1;
	int bx=rx['R']-lx['R'],by=ry['R']-ly['R'];
	if((bx+1)*(by+1)!=cnt['R'])	flag=0;
//	cout<<flag<<endl;
	if(rx['G']-lx['G']!=bx||ry['G']-ly['G']!=by||((bx+1)*(by+1)!=cnt['G']))	flag=0;
//	cout<<flag<<endl;	
	if(rx['B']-lx['B']!=bx||ry['B']-ly['B']!=by||((bx+1)*(by+1)!=cnt['B']))	flag=0;
//	cout<<flag<<endl;
	if(flag)	puts("YES");else puts("NO");
}