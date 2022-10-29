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

map<int,int> minv;
int a[5005];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      for (int j = 0; j <= k; j++)
         if  (minv.count(a[i]*j) == 0) 
         {
            minv[a[i]*j] = j;
         } else minv[a[i]*j] = min(minv[a[i]*j], j);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
       int x;
       cin >> x;
       int ans = (int)1e9;
       for (int j = 0; j < n; j++)
          for (int p = 0; p <= k; p++)
             if (minv.count(x-a[j]*p) != 0) ans = min(ans, p + minv[x-a[j]*p]);
       if (ans > k) cout << -1 << endl;
       else cout << ans << endl;
    }
}