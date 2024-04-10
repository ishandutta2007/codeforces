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
#define inf 1e9
#define ll long long
#define maxn 401000
#define y1 fuck
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
using namespace std;
char c1,c2,s[201][2];
int n;
bool vis1[201],vis2[201],vis3[201],vis4[201];
int main()
{
	c1=getchar();c2=getchar();
	n=read();
	For(i,1,n)	scanf("%s",s[i]+1);
	For(i,1,n)	if(s[i][1]==c1&&s[i][2]==c2){puts("YES");return 0;}
	For(i,1,n)
	{
	
		For(j,1,n)
		{	
			if(s[i][2]==c1&&s[j][1]==c2){puts("YES");return 0;}
		}
	}
	puts("NO");
}