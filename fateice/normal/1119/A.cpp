#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[300010],p;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=n;i++)
      if(x[i]!=x[1])
        p=max(p,i-1);
    for(i=1;i<=n;i++)
      if(x[i]!=x[n])
        p=max(p,n-i);
    cout<<p;
    return 0;
}