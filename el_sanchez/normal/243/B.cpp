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


const int C = (int)1e5 + 10;
vector<int> con[C];
int u[C], v[C];
int n, m, h, t;

int used1[C], used2[C];


int main()
{
   scanf("%d%d%d%d", &n, &m, &h, &t);
   for (int i = 0; i < m; i++)
   {
      int a,b;
      scanf("%d%d", &a, &b);
      a--; b--;
      con[a].pb(b);
      con[b].pb(a);
      u[i] = a;
      v[i] = b;
   }
   int F = 1;
   for (int i = 0; i < n; i++) used1[i] = used2[i] = 0;
   for (int i = 0; i < n; i++) sort(con[i].begin(), con[i].end());
   for (int p = 0; p < 2; p++)
   {
      for (int i = 0; i < m; i++)
      {
         if (con[u[i]].size() < h+1 || con[v[i]].size() < t+1) continue;
         F++;
         vector<int> pool1,pool2,pool;
         for (int j = 0; j < (int)con[u[i]].size() && pool.size() < (h+t); j++)
         {
             if (con[u[i]][j] == v[i]) continue;
             pool1.pb(con[u[i]][j]);
             used1[con[u[i]][j]] = F;
         }
         for (int j = 0; j < (int)con[v[i]].size() && pool.size() < 2*(h+t); j++)
         {
             if (con[v[i]][j] == u[i]) continue;
             pool2.pb(con[v[i]][j]);
             used2[con[v[i]][j]] = F;
         }
       //  cout << u[i] << ' ' << v[i] << endl;
        // cout << "???" << endl;
         pool.resize(pool1.size()+pool2.size());
         merge(pool1.begin(), pool1.end(), pool2.begin(), pool2.end(), pool.begin());
         pool.erase(unique(pool.begin(), pool.end()), pool.end());
        // cout << "!!!" << endl;
         vector<int> mt, mh;
         
         int trest = t, hrest = h;
         for (int j = 0; j < (int)pool.size(); j++)
         {
          //  cout << "j=" << j << endl;
            if (used1[pool[j]] == F && used2[pool[j]] != F) 
            {
                mh.pb(pool[j]);
                hrest--;
            }
            if (used1[pool[j]] != F && used2[pool[j]] == F)
            {
                mt.pb(pool[j]);
                trest--;
            }
            if (used1[pool[j]] == F && used2[pool[j]] == F)
            {
                if (trest > hrest)
                {
                   mt.pb(pool[j]);
                   trest--;
                }
                else
                {
                   mh.pb(pool[j]);
                   hrest--;
                }
            }
         }

         if (mh.size() >= h && mt.size() >= t)
         {
             cout << "YES" << "\n";
             cout << u[i]+1 << ' ' << v[i]+1 << endl;
             for (int j = 0; j < h; j++) cout << mh[j]+1 << " \n"[j==h-1];
             for (int j = 0; j < t; j++) cout << mt[j]+1 << " \n"[j==t-1];
             return 0;

         }
      }
      for (int i = 0; i < m; i++) swap(u[i],v[i]);
   }
   cout << "NO\n";
   return 0;
}