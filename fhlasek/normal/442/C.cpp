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

#define MAXN 555555
int N, A[MAXN];
int Next[MAXN], Prev[MAXN];
queue<int> q;

long long ans;

bool dip(int i) {
  return i != 0 && i != N - 1 && A[Prev[i]] > A[i] && A[Next[i]] >= A[i];
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  if (N == 1) { printf("0\n"); return 0; }
  REP(i, N) { Next[i] = i + 1; Prev[i] = i - 1; }
  REP(i, N) if (dip(i)) q.push(i);

  while (!q.empty()) {
    int n = q.front(), l = Prev[n], r = Next[n];
    q.pop();
    ans += min(A[l], A[r]);
    Prev[r] = l;
    Next[l] = r;
    if (dip(l)) q.push(l);
    if (dip(r)) q.push(r);
  }

  vector<int> v;
  int p = 0;
  while (p != N) {
    v.push_back(p);
    p = Next[p];
  }

  int l = 0, r = (int)v.size() - 1;
  while (l + 1 != r) {
    ans += min(A[v[l]], A[v[r]]);
    if (min(A[v[l]], A[v[r - 1]]) > min(A[v[l + 1]], A[v[r]])) r--;
    else l++;
    /*
    if (false) {}
    else if (A[v[l]] < A[v[r]]) l++;
    else if (A[v[l]] > A[v[r]]) r--;
    else if (A[v[l + 1]] < A[v[r - 1]]) l++;
    else if (A[v[l + 1]] > A[v[r - 1]]) r--;
    else r--;
    */
  }

  cout << ans << endl;
  return 0;
}