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

const int C = (int)2e5 + 19;
int h[C], w[C], ph[C], sh[C];

int main()
{
   int n;
   scanf("%d", &n);
   int SW = 0;
   for (int i = 0; i < n; i++)
   {
     scanf("%d%d", &w[i], &h[i]);
     SW += w[i];
   }
   ph[0] = h[0];
   for (int i = 1; i < n; i++) ph[i] = max(ph[i-1], h[i]);
   sh[n-1] = h[n-1];
   for (int i = n-2; i >= 0; i--) sh[i] = max(sh[i+1], h[i]);
   for (int i = 0; i < n; i++)
   {
      printf("%d%c", max((i==0?0:ph[i-1]), (i==n-1?0:sh[i+1])) * (SW - w[i]), " \n"[i==n-1]);
   }
}