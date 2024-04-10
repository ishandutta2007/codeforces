// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1021;
int n, m, c[N], a[N];
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>c[i];
  for(int i=0; i<m; i++) cin>>a[i];
  int ans=0, ptr=0;
  for(int i=0; i<n; i++){
    if(ptr>=m) break;
    if(a[ptr]>=c[i]){
      ans++;
      ptr++;
    }
  }
  cout<<ans<<endl;
}