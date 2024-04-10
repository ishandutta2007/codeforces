#include <bits/stdc++.h>

using namespace std;

const int N=70+7;
int n;
int a[N];
#define int long long

signed main()
{
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while (t--)
  {
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    int sol=n-1;
    for (int i=1;i<=n;i++){
      for (int j=i+1;j<=n;j++){
        /**

        t(i)=a+i*b
        t(j)=a+j*b

        t(i)-i*b=t(j)-j*b

        b*(j-i)=t(j)-t(i)

        **/
        int cst=0;
        for (int k=1;k<=n;k++){
          if(k==i||k==j) continue;
          if((a[j]-a[i])*(k-i)!=(a[k]-a[i])*(j-i)){
            cst++;
          }
        }
        sol=min(sol,cst);
      }
    }
    cout<<sol<<"\n";
  }
}