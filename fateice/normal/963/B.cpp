#include<bits/stdc++.h>
#define L long long
#define pb push_back
using namespace std;
int n;
bool x[200010];
vector<int> a[200010];
inline void dfs2(int i)
{
    x[i]=1;
    printf("%d\n",i);
    for(auto j:a[i])
      if(!x[j])
        dfs2(j);
}
inline void dfs(int i,int j)
{
    int k=0;
    for(auto l:a[i])
      if(l!=j && !x[l])
        dfs(l,i);
    for(auto l:a[i])
      if(l!=j && !x[l])
        k++;
    if(j)
      k++;
    if(k%2==0)
      {
       printf("%d\n",i);
       x[i]=1;
       for(auto l:a[i])
         if(l!=j && !x[l])
           dfs2(l);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&j);
       if(j)
         a[i].pb(j),a[j].pb(i);
      }
    if(n%2==0)
      printf("NO\n");
    else
      {
       printf("YES\n");
       dfs(1,0);
      }
	return 0;
}