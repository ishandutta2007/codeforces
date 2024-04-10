/* Writen by Filip Hlasek 2012 */
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

#define EPS 1e-9

long long sq(int x){ return (long long)x * x; }

const int A = 100000, B = 1000000;

int main(int argc, char *argv[]){
  int X = 0;
  double R = A;
  printf("335\n");
  printf("%d %d\n", X, A);
  REP(i, 333){
    int Nx = 2 * R - EPS + X;
    if(!i) Nx = 10000;
    R = (double)(Nx - X) * (Nx - X) / (4 * R);
    X = Nx;
    printf("%d %d\n", X, B);
  }
  printf("%d %d\n",(int)sqrt(sq(B + A) - sq(B - A)) - 10, B);
  return 0;
}