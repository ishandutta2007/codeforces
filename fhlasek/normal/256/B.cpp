/* Written by Filip Hlasek 2012 */
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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int N, X, Y;
long long cells(int steps){
  long long ans = 2 * (long long)steps * (steps + 1) + 1;
  if(X + steps > N) ans -= (long long)(X + steps - N) * (X + steps - N);
  if(Y + steps > N) ans -= (long long)(Y + steps - N) * (Y + steps - N);
  if(X - steps <= 0) ans -= (long long)(1 - (X - steps)) * (1 - (X - steps));
  if(Y - steps <= 0) ans -= (long long)(1 - (Y - steps)) * (1 - (Y - steps));
  long long n = steps - (N - X + N - Y + 1);
  if(n > 0) ans += n * (n + 1) / 2;
  n = steps - (X - 1 + Y - 1 + 1);
  if(n > 0) ans += n * (n + 1) / 2;
  n = steps - (X - 1 + N - Y + 1);
  if(n > 0) ans += n * (n + 1) / 2;
  n = steps - (N - X + Y - 1 + 1);
  if(n > 0) ans += n * (n + 1) / 2;
  return ans;
}

int main(int argc, char *argv[]){
  int C; 
  scanf("%d%d%d%d", &N, &X, &Y, &C);
  int left = 0, right = 2 * N, middle;
  while(left < right){
    middle = (left + right) / 2;
    if(cells(middle) >= C) right = middle;
    else left = middle + 1;
  }
  printf("%d\n", left);
  return 0;
}