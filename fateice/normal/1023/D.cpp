#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[200010],l[200010],r[200010];
vi a[200010],b[200010];
set<int> f;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	l[1]=1;
	r[1]=n;
	for(i=2;i<=m;i++)
      l[i]=n+1;
    for(i=1;i<=n;i++)
      {
       l[x[i]]=min(l[x[i]],i);
       r[x[i]]=max(r[x[i]],i);
      }
    if(!r[m])
      {
       for(i=1;i<=n;i++)
         if(!x[i])
           {
            l[m]=r[m]=i;
            break;
           }
       if(i>n)
         {
          printf("NO");
          exit(0);
         }
      }
    for(i=1;i<=m;i++)
      if(r[i])
        {
         a[l[i]].pb(i);
         b[r[i]].pb(i);
        }
    for(i=1;i<=n;i++)
      {
       for(auto j:a[i])
         f.insert(-j);
       j=-*f.lower_bound(-m);
       if(x[i]==0 || x[i]==j)
         x[i]=j;
       else
         {
          printf("NO");
          exit(0);
         }
       for(auto j:b[i])
         f.erase(-j);
      }
    printf("YES\n");
    for(i=1;i<=n;i++)
      printf("%d ",x[i]);
	return 0;
}