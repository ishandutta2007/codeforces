/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int main(int argc, char *argv[]){
  long long a, b, m, ans = 0;
  cin >> a >> b >> m;
  while (a < m && b < m) {
    if (a > b) swap(a, b);
    if (a + b <= a) { ans = -1; break; }
    if (a < 0) { 
      long long d = -a / b;
      a += d * b;
      ans += d;
    }
    a = a + b;
    ans++;
  }
  cout << ans << endl;
  return 0;
}