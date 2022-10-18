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

double deg(double d){ return d / 180 * M_PI; }

int main(int argc, char *argv[]){
  int N;
  scanf("%d", &N);
  printf("%d\n", 1 + 4 * N);
  printf("%.15lf %.15lf\n", (double)0, (double)0);
  double dist = sqrt(5 * 5 + 5 * tan(deg(54)) * 5 * tan(deg(54)));
  REP(i, N){
    printf("%.15lf %.15lf\n", (double)i * 5 + 5 + cos(deg(18)) * dist, (double)i * 5 * tan(deg(72)) + 5 * tan(deg(54)) + sin(deg(18)) * dist);
    printf("%.15lf %.15lf\n", (double)i * 5 + 5 - cos(deg(18)) * dist , (double)i * 5 * tan(deg(72)) + 5 * tan(deg(54)) + sin(deg(18)) * dist );
    printf("%.15lf %.15lf\n", (double)i * 5 + 10, (double)i * 5 * tan(deg(72)));
    printf("%.15lf %.15lf\n", (double)i * 5 + 5, (double)(i+1) * 5 * tan(deg(72)));
  }
  REP(i,N){
    printf("%d %d %d %d %d\n", 1 + 4*i, 3 + 4*i, 5 + 4*i, 2 + 4*i, 4 + 4*i);
  }
  printf("1");
  REP(i, N) printf(" %d %d %d %d", 2 + 4*i, 3 + 4*i, 4 + 4*i, 5 + 4*i);
  REP(i, N) printf(" %d", 1 + 4*(N - i - 1));
  printf("\n");
  return 0;
}