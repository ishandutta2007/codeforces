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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
char input[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%s", input);
  N = strlen(input);

  long long ans0 = 0, ans1 = 0;
  int cnt0a = 0, cnt1a = 0, cnt0b = 0, cnt1b = 0;
  REP(i, N) {
    if (i % 2 == 0 && input[i] == 'a') { cnt0a++; ans0 += cnt1a; ans1 += cnt0a; }
    if (i % 2 == 1 && input[i] == 'a') { cnt1a++; ans0 += cnt0a; ans1 += cnt1a; }
    if (i % 2 == 0 && input[i] == 'b') { cnt0b++; ans0 += cnt1b; ans1 += cnt0b; }
    if (i % 2 == 1 && input[i] == 'b') { cnt1b++; ans0 += cnt0b; ans1 += cnt1b; }
  }

  cout << ans0 << " " << ans1 << endl;
  return 0;
}