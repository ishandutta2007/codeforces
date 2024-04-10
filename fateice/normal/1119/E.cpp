#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[300010];
L s[300010],p,q,r,ans;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    for(i=1;i<=n;i++)
      s[i]=s[i-1]+x[i];
    for(i=n;i>0;i--)
      {
       if(x[i]%2==1 && p>0)
         p--,ans++,x[i]--;
       if(x[i]%2==1 && x[i]>1)
         x[i]-=3,ans++;
       if(p+x[i]/2<=s[i-1])
         p+=x[i]/2;
       else
         {
          q=x[i]/2;
          r=min(min(q,(p+q)/3),(p+q-s[i-1]+2)/3);
          p-=2*r;
          q-=r;
          ans+=2*r;
          p+=q;
          if(q>0 && p==2 && s[i-1]==0)
            ans++,p=0;
         }
      }
    cout<<ans;
    return 0;
}