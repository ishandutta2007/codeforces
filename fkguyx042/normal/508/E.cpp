#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define Maxn 200005
using namespace std;
const int INF=(int)1e9;
const double eps=1e-10;
const double pi=acos(-1.0);
int i,j,m,n,p,k,a[Maxn],tot;
int Last[1505],l[1505],r[1505],Ans[1505],ans[1505];
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i) scanf("%d%d",&l[i],&r[i]);
	for (i=n-1;i>=0;--i)
	{
		 int Now=1;
		 for (;Now<l[i]&&tot;) Now+=Last[tot],--tot;
		 if (Now>r[i]||Now<l[i]) { printf("IMPOSSIBLE\n"); return 0; }
		 Ans[i]=Now; Last[++tot]=Now+1;
   }
   for (i=0,j=0;i<2*n;++i)
     if (!ans[i]) ans[i+Ans[j]]=1,++j;
   for (i=0;i<2*n;++i) if (ans[i]) printf(")"); else printf("(");
}