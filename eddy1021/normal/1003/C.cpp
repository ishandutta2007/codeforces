#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5050;
int n, k, a[N];
int main(){
  cin>>n>>k;
  for(int i=1; i<=n; i++){
    cin>>a[i];
    a[i]+=a[i-1];
  }
  double ans=0;
  for(int i=1; i<=n; i++)
    for(int j=i+k-1; j<=n; j++){
      double tans=a[j]-a[i-1];
      tans/=(j-i+1);
      ans=max(ans, tans);
    }
  printf("%.12f\n", ans);
}