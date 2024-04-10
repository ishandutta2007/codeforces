#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005

using namespace std;

int A[N],a[N],i,j,n,ans,sum,k,ansl,ansr;
void ins(int x) { A[x]++; if (A[x]==1) ++sum; }
void del(int x) { A[x]--; if (!A[x]) --sum; }
int main()
{
   scanf("%d%d",&n,&k);
   for (i=1;i<=n;++i) scanf("%d",&a[i]);
   j=1; A[a[1]]++; sum=1;
   for (i=1;i<=n;++i)
   {
       while (j<=n&&sum<=k) ins(a[++j]);
       if (j-i>ans)
       {
         ans=max(ans,j-i);
         ansl=i; ansr=j-1; 
       }del(a[i]);
   }
   printf("%d %d\n",ansl,ansr);
}