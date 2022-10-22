#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int INF=(int)1e18+7;
const int N=500+7;
int n;
int c[N][N];
int mn;

void rep(int i,int j){
  if(max(i,j)<=n/2||min(i,j)>n/2)assert(0);
  assert(1<=i&&1<=j&&i<=n&&j<=n);
  mn=min(mn,c[i][j]);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    cin>>n;
    n*=2;
    mn=INF;
    for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
        cin>>c[i][j];
      }
    }
    int sum=0;
    for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
        if(max(i,j)<=n/2||min(i,j)>n/2){
          sum+=c[i][j];
        }
      }
    }
    rep(1,n/2+1);
    rep(1,n);
    rep(n/2,n/2+1);
    rep(n/2,n);

    rep(n/2+1,1);
    rep(n/2+1,n/2);
    rep(n,1);
    rep(n,n/2);
    cout<<sum+mn<<"\n";
  }

  return 0;
}