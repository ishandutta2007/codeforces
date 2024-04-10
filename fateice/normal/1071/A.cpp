#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,a[100010],b[100010],p,q;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(k=1;(L)k*(k+1)/2<=n+m;k++);
    k--;
    for(i=k;i>0;i--)
      if(n>=i)
        {
         n-=i;
         a[++p]=i;
        }
      else
        {
         m-=i;
         b[++q]=i;
        }
    printf("%d\n",p);
    for(i=1;i<=p;i++)
      printf("%d ",a[i]);
    printf("\n");
    printf("%d\n",q);
    for(i=1;i<=q;i++)
      printf("%d ",b[i]);
    printf("\n");
    return 0;
}