#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define x first
#define y second

typedef long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 1000*1000*1000 + 7;
const LL LINF = MOD * (LL)MOD;

int n, m;
int a[7777];
PII x[7777];
int res1[7777];
int res2[7777];
set<PII> q;
vector<int> z[7777];
LL ans = 0, num = 1;

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);

  cin >> n >> m;
  FOR (i,0,n) cin >> a[i];
  FOR (i,0,m) {
    cin >> x[i].first >> x[i].second;
    q.insert(x[i]);
    z[x[i].first].push_back(x[i].second);
  }

  FOR (i,0,n+1) sort(z[i].begin(), z[i].end());

  FOR (pref,0,n) {
    FOR (i,0,n+1) res1[i] = res2[i] = 0;
    FOR (i,0,n)
    {
      if (i <= pref) res1[a[i]]++;
      else res2[a[i]]++;
    }

    PII expectedEndLeft = MP(a[pref], res1[a[pref]]);
    if (q.count(expectedEndLeft) == 0)
      continue;

    LL NUM = 1, Q = 1;
    FOR (t,0,n+1)
    {
      int cl = res1[t], cr = res2[t];
      int MLT = 0;

      if (t == expectedEndLeft.first) {
        FOR (i,0,z[t].size()) {
          if (z[t][i] <= cr && z[t][i] != expectedEndLeft.second) {
            MLT++;
          }
        }
        if (MLT > 0) NUM++, Q = (Q*MLT)%MOD;
      } else {
        if (cl < cr) swap(cl, cr);
        if (z[t].size() >= 2 && cl >= z[t][1] && cr >= z[t][0]) {
          NUM+=2;
          //add
          int MLTR = 0;
          FOR (i,0,z[t].size()) {
            if (z[t][i] <= cl) MLT++;
            if (z[t][i] <= cr) MLTR++;
          }
          LL RES = (MLT-MLTR)*1LL*MLTR + MLTR * 1LL * (MLTR-1);
          Q = (Q*RES)%MOD;
        } else if (z[t].size() >= 1 && cl >= z[t][0]) {
          NUM++;
          //add
          FOR (i,0,z[t].size()) {
            if (z[t][i] <= cr) MLT++;
            if (z[t][i] <= cl) MLT++;
          }
          Q = (Q*MLT)%MOD;
        }
      }
    }

//cout << pref<<": "<<NUM<<" "<<Q<<endl;
    if (NUM > ans) ans = NUM, num = 0;
    if (NUM == ans) num += Q;
    num %= MOD;
  }

   // -1
    {
        FOR (i,0,n+1) res1[i]=0;
        FOR (i,0,n) res1[a[i]]++;

        LL NUM = 0, Q = 1;
        FOR (t,0,n+1)
        {
          int cl = res1[t];
          int MLT = 0;
          if (z[t].size() >= 1 && cl >= z[t][0]) {
            NUM++;
            //add
            FOR (i,0,z[t].size()) {
              if (z[t][i] <= cl) MLT++;
            }
            Q = (Q*MLT)%MOD;
          }
        }

        //cout << "-1: "<<NUM<<" "<<Q<<endl;
        if (NUM > ans) ans = NUM, num = 0;
        if (NUM == ans) num += Q;
        num %= MOD;
    }

  if (ans == 0) num = 1;
  cout << ans<<" "<<num<<"\n";
}