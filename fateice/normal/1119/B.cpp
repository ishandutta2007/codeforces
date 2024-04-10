#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[1010],h;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j,k;
    scanf("%d%d",&n,&h);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=n;i++)
      {
       sort(x+1,x+i+1);
       k=0;
       for(j=i;j>0;j-=2)
         k+=x[j];
       if(k>h)
         break;
      }
    cout<<i-1;
    return 0;
}