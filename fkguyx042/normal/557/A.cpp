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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
int Min[5],Max[5];		
void dfs(int x)
{
	 if (x==4) return;
	 int A=0,B=0,i;
	 for (i=x+1;i<=3;++i) A+=Min[i],B+=Max[i];
	 for (i=Max[x];;--i) if (A+i<=n&&B+i>=n) break;
	 printf("%d\n",i); n-=i;
	 dfs(x+1);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=3;++i) scanf("%d%d",&Min[i],&Max[i]);
	dfs(1);
}