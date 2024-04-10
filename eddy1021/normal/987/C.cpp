#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3030;
int n, s[N], c[N];
int main(){
  int ans=1e9;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>s[i];
  for(int i=1; i<=n; i++) cin>>c[i];
  for(int i=1; i<=n; i++){
    int l=6e8, r=6e8;
    for(int j=1; j<i; j++)
      if(s[j] < s[i])
        l=min(l, c[j]);
    for(int j=n; j>i; j--)
      if(s[j] > s[i])
        r=min(r, c[j]);
    ans=min(ans, l+r+c[i]);
  }
  if(ans>5e8) ans=-1;
  cout<<ans<<endl;
}