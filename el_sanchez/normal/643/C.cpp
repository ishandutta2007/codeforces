#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
#define X first
#define Y second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

const int maxn = (int)2e5 + 5;
const int maxk = 55;
ld a[maxn], ra[maxn], S[maxn], R[maxn], Q[maxn];
ld dp[maxk][maxn];
           
typedef pair<ld,ld> line;
typedef pair<ld,ld> seg;

ld inters(const line &a, const line &b)
{
 //  cerr << a.X << ' ' << a.Y << "   " << b.X << ' ' << b.Y << endl;
   if (fabs(a.X-b.X) > 1e-9)
      return (b.Y - a.Y) / (a.X - b.X);
   else
   {
       if (a.Y > b.Y) return -1e18;
       else return 1e18;
   }
}

void add_line(vector<line> &st1, vector<seg> &st2, line nw)
{
    while (st1.size() > 0 && st2.back().X > inters(st1.back(), nw)) 
        {st1.pop_back(), st2.pop_back();}
    assert(st1.size() > 0 && st1.size() == st2.size());
    st2.back().Y = inters(st1.back(), nw);
    st2.pb(mp(inters(st1.back(), nw), 1e18));
   // cout << nw.X << ' ' << nw.Y << endl;
    st1.pb(nw);
    
}

ld getf(vector<line> &st1, vector<seg> &st2, ld x)
{
   int id = lower_bound(st2.begin(), st2.end(), mp(x, x-1.)) - st2.begin();
   id--;
  // cerr << "id=" << id << endl;
   assert(id >= 0 && id < (int)st1.size());
   return x * st1[id].X + st1[id].Y;
}


int main()
{                      
   int n,k;
   scanf("%d%d", &n, &k);
   for (int i = 1; i <= n; i++)
   {
      int xx;
      scanf("%d", &xx);
      a[i] = xx;
      ra[i] = 1./a[i];
   }
   a[0] = ra[0] = 0;
   S[0] = R[0] = Q[0] = 0;
   for (int i = 1; i <= n; i++)
   {
      S[i] = S[i-1] + ra[i];
      R[i] = R[i-1] + a[i] * S[i];
      Q[i] = Q[i-1] + a[i];
   }

   dp[0][0] = 0;
   for (int i = 1; i <= n; i++)
      dp[0][i] = 1e15;
   for (int j = 1; j <= k; j++)
   {
      vector<line> st1;
      vector<seg> st2;
      st1.pb(mp(0, 1e15));
      st2.pb(mp(-1e18, 1e18));
     // cerr << "j=" << j << endl;
      for (int i = 0; i <= n; i++)
      {            
         dp[j][i] = getf(st1,st2, S[i]) - R[i] + S[i] * Q[i];
         add_line(st1, st2, mp(-Q[i], dp[j-1][i] + R[i]));
      }
   }
   cout << dp[k][n] + (ld)n << "\n";
   return 0;   
}