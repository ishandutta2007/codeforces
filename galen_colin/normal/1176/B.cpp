#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int cache[300];
int main() {
  io;
  int t; cin >> t;
  f0r(i, t) {
    int n, tot = 0; cin >> n;
    f0r(j, n) {cin >> cache[j]; cache[j] %= 3;}
    
    sort(cache, cache+n);
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < n; i++) {
      if (cache[i] == 0) z++;
      else if (cache[i] == 1) o++;
      else t++;
    }
    tot = z + min(o, t);
    if (t > o) tot += (t - min(o, t)) / 3;
    else tot += (o - min(o, t)) / 3;
    cout << tot << endl;
  }
}