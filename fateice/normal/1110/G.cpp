#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int t,n,x[500010];
vi a[500010];
char s[500010];
inline int get(int i,int j)
{
    if(a[i][0]==j)
    if(a[i].size()!=2)
      {
       cout<<i<<"\n";
       while(1);
      }
    else
      return a[i][1];
    else
      return a[i][0];
}
inline void chk(int i,int j)
{
    if(a[i].size()>3)
      {
       printf("White\n");
       return;
      }
    for(auto k:a[i])
      if(k!=j && a[k].size()>1)
        {
         printf("White\n");
         return;
        }
    printf("Draw\n");
}
inline int dfs(int i,int j,int k)
{
    while(a[i].size()==2)
      swap(i,j),i=get(j,i),k^=1;
    if(a[i].size()>=3)
      return k;
    else
      return 0;
}
inline void solve()
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
      if(s[i]=='W')
        k++;
    if(k>=2 && n>=3)
      {
       if(k==2 && n%2==0)
         {
          for(i=1;i<=n;i++)
            if(!(s[i]=='W' && a[i].size()==1 || s[i]=='N' && a[i].size()==2))
              break;
          if(i>n)
            {
             printf("Draw\n");
             return;
            }
         }
       printf("White\n");
       return;
      }
    if(n<=3)
      {
       printf("Draw\n");
       return;
      }
    if(k==1)
      {
       for(i=1;i<=n;i++)
         if(s[i]=='W')
           break;
       if(a[i].size()>=2)
         {
          printf("White\n");
          return;
         }
       for(j=get(i,0);;)
         if(a[j].size()==1)
           {
            printf("Draw\n");
            return;
           }
         else if(a[j].size()>2)
           {
            printf("White\n");
            return;
           }
         else
           {
            swap(i,j);
            j=get(i,j);
            if(a[j].size()==1)
              {
               printf("Draw\n");
               return;
              }
            else if(a[j].size()>2)
              {
               chk(j,i);
               return;
              }
            else
              swap(i,j),j=get(i,j);
           }
      }
    else
      {
       for(i=1;i<=n;i++)
         if(a[i].size()>=4)
           {
            printf("White\n");
            return;
           }
       for(i=1;i<=n;i++)
         if(a[i].size()==3)
           {
            k=0;
            for(auto j:a[i])
              {
               if(dfs(j,i,0))
                 {
                  printf("White\n");
                  return;
                 }
               if(a[j].size()>1)
                 k++;
              }
            if(k>1)
              {
               printf("White\n");
               return;
              }
           }
       printf("Draw\n");
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%d",&n);
       for(i=1;i<n;i++)
         {
          scanf("%d%d",&j,&k);
          a[j].pb(k);
          a[k].pb(j);
         }
       scanf("%s",&s[0]+1);
       solve();
       for(i=1;i<=n;i++)
         a[i].clear();
      }
	return 0;
}