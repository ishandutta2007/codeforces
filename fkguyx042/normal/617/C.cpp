#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 2005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
double ans=1e18;
struct Node{int x,y;}B[N],A[N];
double sqr(double x)
{
	  return x*x;
}
double dis(Node a,Node b)
{
	  return sqr(a.x-b.x)+sqr(a.y-b.y);
}
double work(int x)
{
	  double Ans=0;
	  int i;
	  for (i=1;i<=n;++i) if (dis(A[0],B[i])>dis(A[0],B[x])) Ans=max(Ans,dis(A[1],B[i]));
	  return Ans;
}
int main()
{ 
    scanf("%d%d%d%d%d",&n,&A[0].x,&A[0].y,&A[1].x,&A[1].y);
    for (i=1;i<=n;++i) scanf("%d%d",&B[i].x,&B[i].y);
    B[0]=A[0];
	for (i=0;i<=n;++i) 
	ans=min(ans,dis(A[0],B[i])+work(i));
	printf("%I64d\n",(long long)ans);
}