#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
#include <ctime>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const ld pi = acos(-1.);
typedef pair<int,int> pii;
#define X first
#define Y second
typedef vector<int> vi;

inline long long mul( long long a, long long b, long long m ) 
{
  long long q = (long long)((long double)a * (long double)b / (long double)m);
  long long r = a * b - q * m;
  return (r + 5ll*m) % m;
} 

ll pow(ll a, ll b, ll n)
{
   ll q = a, ans = 1ll;
   while (b)
   {
      if (b & 1ll) ans = mul(ans, q, n);
      q = mul(q, q, n);
      b >>= 1;
   }
   return ans;
}


bool isprime(ll n)
{
   if ((n != 2ll && n % 2ll == 0ll) || n == 1ll) return 0;
   for (int i = 2; i < min(50,(int)n); i++)
      if (n % (ll)i == 0ll) return 0; 
   for (int it = 0; it < 20; it++)
   {
      ll ev = (((ll)rand() << 31) + (ll)rand()) % n;
      if (ev == 1ll || ev == 0ll) continue;
      int c = 0;
      ll u = n - 1ll;
      while (!(u & 1ll)) {u /= 2ll; c++;}
      ll q = pow(ev, u, n);
      ll prev;
      for (int i = 0; i < c; i++)
      {
         prev = q;
         q = mul(q, q, n);
        if (q == 1ll && prev != n-1ll && prev != 1ll) return 0; 
      }
      if (q != 1ll) return 0;
   }
   return 1;
}


const int C = 200000, C2 = (int)1.1e6;
ll ids[C*3];
int used[C*3];
int vof[C*3];

int thash(ll hash)
{
    return (int)((hash % ll(2*C) * 1223ll + 3434ll)%(ll)(2*C));
}


void nxt(int &a)
{
   a++;
   if (a == 3*C) a = 0;
}

void add(ll val, int data)
{
   int u = thash(val);
   for (; used[u] != -1; nxt(u));
   used[u] = 1;
   ids[u] = val;
   vof[u] = data;
}

bool isin(ll hash)
{
   int u = thash(hash);
   for (; ids[u] != hash; nxt(u))
      if (used[u] == -1) return 0;
   return 1;
}

int getValue(ll hash)
{
   int u = thash(hash);
   for (; ids[u] != hash; nxt(u))
      if (used[u] == -1) return -1;
   return vof[u];
} 

ll d[7005];
ll ch[7005]; //power for d-1
ll ps[7005];

map<ll,ll> powers;
bool er0[C2];

ll dp[2][7005];
vector<ll> ass[7005];
int main()
{
   ll A;
   cin >> A;
   int cnt = 0;
   for (ll u = 1; u*u <= A; u++)
   {
      if (A % u == 0) 
      {
         d[cnt++] = u;
         if (u*u != A) d[cnt++] = A/u;
      }
   } 
   sort(d, d + cnt);
   for (int i = 0; i < 3*C; i++) used[i] = -1;
   for (int i = 0; i < cnt; i++) add(d[i], i);
   for (int i = 0; i < cnt; i++) assert(isin(d[i]));


   for (int i = 0; i < C2; i++)
     er0[i] = 1;

   er0[0] = er0[1] = 0;
   for (int i = 2; i < C2; i++)
      for (int j = i+i; er0[i] && j <= C2; j += i)
         er0[j] = 0;

   for (int i = 2; i < C2; i++)
      if (er0[i])
      {
          ll c = i;
          while (c <= A)
          {
             powers[c] = i;
             c *= (ll)i;
          }
      }
  // cerr << "SOME" << endl;
   int cnt2 = 0;
   for (int i = 0; i < cnt; i++)
   {
      ch[i] = -1;
      if (powers.count(d[i]-1ll) != 0) 
         ch[i] = powers[d[i]-1ll];
      else
      {
         if (isprime(d[i]-1ll)) ch[i] = d[i]-1ll;
         else ch[i] = -1;
      }
      if (ch[i] != -1ll) ps[cnt2++] = ch[i]; 
   }
   sort(ps, ps + cnt2);
   cnt2 = unique(ps, ps + cnt2) - ps;
   //for (int i = 0; i < cnt2; i++) cout << ps[i] << ' ';
  // cout << endl;
   for (int i = 0; i < cnt2; i++) ass[i].clear();
   for (int i = 0; i < cnt; i++)
      if (ch[i] != -1)
      {
         int pos = lower_bound(ps, ps + cnt2, ch[i]) - ps;
        // cout << d[i] << ' ' << ch[i] << ' ' << pos << endl;
         ass[pos].pb(i);
      }
  // for (int i = 0; i < cnt2; i++) cout << ass[i].size() << " ";
  // cout << endl;
 //  for (int i = 0; i < cnt; i++) cout << d[i] << ' ' << ch[i] << endl;
 //  for (int i = 0; i < cnt2; i++) cout << ps[i] << ' ';
 //  cout << endl;
   for (int i = 0; i < cnt; i++) dp[0][i] = dp[1][i] = 0;
   dp[0][0] = 1;
 //  cout << "cnt=" << cnt << " cnt2=" << cnt2 << endl;
   for (int i = 0; i < cnt2; i++)
   {
     // cerr << "i=" << i << endl;
    //  bool dit = i == 1098;
      for (int j = 0; j < cnt; j++)
      {
         if (dp[0][j] == 0) continue;
       //  if (dit) cerr << "j=" << j << endl;
     //    cout << "dp[" << ps[i] << "," << d[j] << "] = " << dp[0][j] << endl;
      //   cout << "sz=" << ass[i].size() << endl;
         for (int k = 0; k < (int)ass[i].size(); k++)
         {
            ll nval = d[j] * d[ass[i][k]];
         //   cout << "(" << i << "," << j << ")  " << nval << endl;
            if (nval >= 0 && nval <= A && isin(nval)) 
            {
               int npos = getValue(nval);
               assert(npos != -1 && npos < cnt);
               dp[1][npos] += dp[0][j];
            }
         }  
         dp[1][j] += dp[0][j];
      //   if (dit) cerr << "fin j=" << j << endl;
      }
    //  cerr << "fin " << i << endl;
    //  for (int j = 0; j < cnt; j++) if (dp[1][j] != 0) cout << "---dp[" << ps[i] << "," << d[j] << "] = " << dp[1][j] << endl;
      for (int j = 0; j < cnt; j++) {dp[0][j] = dp[1][j]; dp[1][j] = 0;}      
   }
   cout << dp[0][cnt-1] << "\n";
   return 0; 
}