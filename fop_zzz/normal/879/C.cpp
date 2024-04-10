#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define inf 1e9
#define ll long long
#define pa pair<int,int>
#define y1 fuck
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int n,t,now,an,OR,XOR;
int f[600001][11];
char s[5];
int main()
{
	n=read();
	For(i,0,9)	
		f[0][i]=2;
	For(i,1,n)
	{
		scanf("%s",s+1);
		int s1=read();
		if(s[1]=='|')
			{For(j,0,9)	if(s1&(1<<j))	f[i][j]=1;else	f[i][j]=f[i-1][j];}
		else	if(s[1]=='&')
			{
				For(j,0,9)	if((s1&(1<<j))==0)	f[i][j]=0;
					else	f[i][j]=f[i-1][j];
			}
		else
			{For(j,0,9)	if(s1&(1<<j))	f[i][j]=f[i-1][j]^1;else	f[i][j]=f[i-1][j];}
	}
	For(i,0,9)	
	{
		if(!f[n][i])	an|=1<<i;
		else
		if(f[n][i]==1)	OR|=1<<i;
			else if(f[n][i]==3)	XOR|=1<<i;
//		cout<<f[n][i]<<endl;
	}
	cout<<3<<endl;
	printf("& %d\n",an^1023);
	printf("| %d\n",OR);
	printf("^ %d\n",XOR);
}