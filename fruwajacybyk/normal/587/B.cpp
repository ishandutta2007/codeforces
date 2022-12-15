#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

int mod = 1e9+7;

int dp[1100007];

int main(){
  int n, k;
  lint l;
  
  scanf("%d%I64d%d",&n,&l,&k);
  makev(v,n);
  vector<PII> w;
  FOR(i,0,n) w.pb(mp(v[i],i));
  sort(all(w));
  
  FOR(i,0,n) dp[0*n + i] = 1;   
  FOR(i,1,k) {
    int suma = 0;
    int lastj = 0;
    int j = 0;
    while (j!=n) {
      while (j < n && w[j].st == w[lastj].st) {
        suma += dp[(i-1)*n + w[j].nd];
        suma %= mod;
        j++;
      }
      FOR(u,lastj,j) {
        dp[i*n + w[u].nd] = suma;
      }
      lastj = j;
    }
  }
  lint pelne = l/n, reszta = l%n;
  int answer = 0;
  FOR(i,0,k) {
    lint mozl = max(pelne-i, 0LL);
    int dupa = 0;
    int dupa2 = 0;
    FOR(j,0,n) {
      dupa += dp[i*n + j];
      dupa %= mod;
      if (j < reszta) {
        dupa2 += dp[i*n+j];
        dupa2 %= mod;
      }
    }
    mozl = mozl%mod;
    answer += (mozl*1LL*dupa)%mod;
    answer %= mod;
    if (pelne>=i) {
      answer += dupa2;
      answer %= mod;
    }
  }
  printf("%d\n",answer);
  
  

  

}