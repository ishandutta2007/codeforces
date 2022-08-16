#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, X[100000], Y[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  vector< pair< long double, int > > P;
  for(int i = 0; i < N; i++) P.emplace_back(atan2l(Y[i], X[i]), i);
  sort(begin(P), end(P));
  P.emplace_back(P.front());
  P.back().first += 8 * atanl(1);
  long double ret = 1e30;
  int a, b;
  for(int i = 0; i < N; i++) {
    if(P[i + 1].first - P[i].first < ret) {
      ret = P[i + 1].first - P[i].first;
      a = P[i + 1].second;
      b = P[i].second;
    }
  }
  cout << a + 1 << " " << b + 1 << endl;
}