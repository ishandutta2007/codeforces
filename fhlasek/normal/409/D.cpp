/* Written by Filip Hlasek 2014 */
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

int ans[20] = {
  0, // nothing
  1, // Everest
  0, // game
  0, // math
  1, // Nile
  0, // Amazon
  1, // waterfall
  0, //Hotel
  1, //Uranium
  1, // coldest place
  1, //Snake Medusa
  0, //Cat Meow
  0, // sea otter 
  1, // Alaska area
  0, // Coast
  1, // Baikal
  0  // Turkmenistan
};

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n]);
  return 0;
}