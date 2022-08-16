#include <bits/stdc++.h>

using namespace std;


int main() {
  int N, U, E[100000];
  cin >> N >> U;
  for(int i = 0; i < N; i++) {
    cin >> E[i];
  }

  double ret = -1;

  for(int i = 1; i < N - 1; i++) {
    int E_i = E[i - 1], E_j = E[i];

    auto it = upper_bound(E, E + N, E_i + U) - E;
    --it;
    if(it <= i) continue;
    ret = max(ret, 1.0 * (E[it] - E_j) / (E[it] - E_i));
  }
  if(ret < 0) puts("-1");
  else printf("%.10lf\n", ret);
}