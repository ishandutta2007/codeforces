#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 205
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
char s[N];
int i,j,m,n,p,k,f[N][N][N],a,b,c;
void dfs(int x,int y,int z)
{
	 if (f[x][y][z]) return;
	 f[x][y][z]=1;
	 if (x>=2) dfs(x-1,y,z);
	 if (y>=2) dfs(x,y-1,z);
	 if (z>=2) dfs(x,y,z-1);
	 if (x&&y) dfs(x-1,y-1,z+1);
	 if (x&&z) dfs(x-1,y+1,z-1);
	 if(y&&z)  dfs(x+1,y-1,z-1);
}
int main()
{
	  scanf("%d",&n);
	  scanf("%s",s);
	  for (i=0;i<n;++i)
	  {
	  	  if (s[i]=='B') ++a;
	  	  if (s[i]=='G') ++b;
	  	  if (s[i]=='R') ++c;
	  }
	  dfs(a,b,c);
	  if (f[1][0][0]) putchar('B');
	  if (f[0][1][0]) putchar('G');
	  if (f[0][0][1]) putchar('R');
}