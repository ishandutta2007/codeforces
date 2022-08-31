#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<double,P> Q;

const double eps = 1e-10;
const int MX = 405, INF = 100000000;

int n;
int x[MX], y[MX];
ll dp[6][MX][MX];
Q e[MX*MX]; int ei;

int main(){
  int te;
  //scanf("%d",&te);
  te = 1;
  while(te--){
    scanf("%d",&n);

    rep(i,n) scanf("%d%d",&x[i],&y[i]);

    rep(k,6)rep(i,n)rep(j,n) dp[k][i][j] = 0;

    ei = 0;
    rep(i,n){
      dp[0][i][i] = 1;
      rep(j,n){
        if(i == j) continue;
        e[ei++] = Q(atan2(x[j]-x[i],y[j]-y[i]),P(i,j));
      }
    }

    sort(e,e+ei);

    int a, b;
    rep(i,ei){
      a = e[i].se.fi;
      b = e[i].se.se;

      rep(k,5)rep(j,n) dp[k+1][j][b] += dp[k][j][a];
    }

    ll ans = 0;
    rep(i,n) ans += dp[5][i][i];

    printf("%lld\n",ans);
  }

  return 0;
}