#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, c[6], tot;
int main(){
  cin>>n;
  for(int i=0, x; i<n; i++){
    cin>>x;
    c[x]++;
    tot+=x;
  }
  int nxt=0, ans=0;
  while((tot+n/2)/n < 5){
    while(c[nxt] == 0) nxt++;
    tot+=5-nxt;
    ans++;
    c[nxt]--;
  }
  cout<<ans<<endl;
}