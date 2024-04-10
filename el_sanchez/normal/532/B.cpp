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

const int C = (int)2e5 + 5;
vector<int> kids[C];
ll d[C], mv[2][C];

void dfs(int v)
{
   mv[0][v] = 0;
   mv[1][v] = (ll)-1e18;
   for (int i = 0; i < (int)kids[v].size(); i++)
   {
      int to = kids[v][i];
      dfs(to);
      ll n0 = max(mv[0][v] + mv[0][to], mv[1][v] + mv[1][to]);
      ll n1 = max(mv[0][v] + mv[1][to], mv[1][v] + mv[0][to]);
      n1 = max(n1, mv[1][to]);
      mv[0][v] = n0;
      mv[1][v] = n1; 
   }
 //  cout << "v=" << v << ": " << mv[0][v] << ' ' << mv[1][v] << endl;
   mv[1][v] = max(mv[1][v], mv[0][v] + d[v]);
 //  cout << "v=" << v << ": " << mv[0][v] << ' ' << mv[1][v] << endl;
}

int main()
{
   int n;
   scanf("%d", &n);
   int root = -1;
   
   for (int i = 0; i < n; i++)
   {
      int p;
      scanf("%d%d", &p, &d[i]);
      if (p == -1) root = i;
      p--;
      kids[p].pb(i);
   }
   dfs(0);
   cout << max(mv[0][0], mv[1][0]) << endl;
}