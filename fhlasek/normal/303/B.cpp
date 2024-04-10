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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int N, M, X, Y, A, B; 

int main(int argc, char *argv[]){
  scanf("%d%d%d%d%d%d", &N, &M, &X, &Y, &A, &B);
  int d = gcd(A, B);
  A /= d; B /= d;
  long long left = 1, right = 1000000000, middle;
  while (left < right) {
    middle = (left + right + 1) / 2;
    if (middle * A > N || middle * B > M) right = middle - 1;
    else left = middle;
  }
  A *= left; B *= left;
  int x1 = min(N - A, max(0, X - (A + 1)/2)) , y1 = min(M - B, max(0, Y - (B + 1)/2));;
  printf("%d %d %d %d\n", x1, y1, x1 + A, y1 + B);
  return 0;
}