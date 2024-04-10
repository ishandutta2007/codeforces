#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int>v[605];
int i,j,m,n,Mo,k,ru[605],chu[605],Sum[605][605],f[605],A[605][605],x,y;
int N,Ans;
int power(int x,int y)
{
	 int sum=1;
	 for (;y;y>>=1)
	 {
			 if (y&1) sum=1ll*sum*x%Mo;
			 x=1ll*x*x%Mo;
	 }
	 return sum;
}
int dfs(int x)
{
	  int i;
	  if (f[x]!=-1) return f[x];
	  f[x]=0;
	  for (i=0;i<(int)v[x].size();++i) (f[x]+=dfs(v[x][i]))%=Mo;
	  return f[x];
}
void check(int x)
{
	   N++;
	   memset(f,-1,sizeof(f));
	   int i,L=0; f[x]=1;
	   for (i=1;i<=n;++i) if (!chu[i]) A[N][++L]=dfs(i);
}
int main()
{
	 scanf("%d%d%d",&n,&m,&Mo);
	 for (i=1;i<=m;++i)
	{
		 scanf("%d%d",&x,&y);
		 chu[x]++; ru[y]++;
		 v[y].push_back(x);
	}
	Ans=1;
	for (i=1;i<=n;++i) if (!ru[i]) check(i);
	for (i=1;i<=N;++i)
	{
		  for (j=i;j<=N;++j) if (A[j][i]) break;
		  if (j>N) { printf("0\n"); return 0; }
		  if (j!=i)
		  {
				for (k=1;k<=N;++k) swap(A[i][k],A[j][k]);
				Ans*=-1;
	      }
	      for (j=i+1;j<=N;++j)
	        if (A[j][i])
	        {
				int PP=1ll*A[j][i]*power(A[i][i],Mo-2)%Mo;
				for  (k=i;k<=N;++k)
				   A[j][k]=(A[j][k]-1ll*A[i][k]*PP%Mo+Mo)%Mo;
			}
   }
   for (i=1;i<=N;++i) Ans=1LL*Ans*A[i][i]%Mo;
   printf("%d\n",(Ans+Mo)%Mo);
}