/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 111111
int N;
long long B[MAXN];

vector<long long> b, nb;

bool solve() {
  b.reserve(N);
  nb.reserve(N);
  int pos = 0;
  FORD(bit, 59, 0) {
    nb.resize(0);
    reverse(b.begin(), b.end());
    long long x = 0;
    while (pos < N && (B[pos] & (1LL << bit))) {
      while ((x ^ B[pos]) <= x && !b.empty()) {
        nb.push_back(b.back());
        x ^= b.back();
        b.pop_back();
      }
      if ((x ^ B[pos]) <= x) return false;
      nb.push_back(B[pos]);
      x ^= B[pos];
      pos++;
    }
    while (!b.empty()) {
      nb.push_back(b.back());
      b.pop_back();
    }
    b = nb;
  }
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) cin >> B[i];
  sort(B, B + N);
  reverse(B, B + N);

  if (!solve()) printf("No\n");
  else {
    printf("Yes\n");
    REP(i, N) {
      if (i) cout << " ";
      cout << b[i];
    }
    cout << endl;
  }

  return 0;
}