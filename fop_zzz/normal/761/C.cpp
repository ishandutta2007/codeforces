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
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline void read(int &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
using namespace std;
char s[1001];
int n,m,mp[1001],ki[1001][1001];
int mi[4];
int main()
{
	scanf("%d %d",&n,&m);
	mp['#']=mp['*']=mp['&']=1;
	For(i,0,25)	mp['a'+i]=2;For(i,0,9)	mp['0'+i]=3;	
	For(i,1,n)	For(j,1,3)	ki[i][j]=1e8;
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		For(j,m+1,2*m)	s[j]=s[j-m];
		int p=m+1;
		For(t,0,m-1)
		{
			ki[i][mp[s[p+t]]]=min(ki[i][mp[s[p+t]]],t);
			ki[i][mp[s[p-t]]]=min(ki[i][mp[s[p-t]]],t);
		}	
	}
	int ans=1e9;
	For(i,1,n)
		For(j,1,n)
			For(k,1,n)
			{
				if(i==j||j==k)	continue;
				ans=min(ans,ki[i][1]+ki[j][2]+ki[k][3]);
			}
	printf("%d",ans);
}