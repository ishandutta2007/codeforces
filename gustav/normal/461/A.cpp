#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)


#define MAXN 300005

int N;
llint sol;
llint sum[MAXN];
int a[MAXN];

void toastman(int l, int r);
void appleman(int l, int r);

void toastman(int l, int r) {
  sol += sum[r] - sum[l - 1];
  appleman(l, r);
}

void appleman(int l, int r) {
  if (l == r) {
    return;
  } else {
    toastman(l, l);
    toastman(l + 1, r);
  }
}

int main(void)
{
  cin >> N;
  FOR(i, 1, N + 1) cin >> a[i];
  sort(a + 1, a + N + 1);
  FOR(i, 1, N + 1) sum[i] = a[i] + sum[i - 1];

  toastman(1, N);

  cout << sol;

  return 0;
}