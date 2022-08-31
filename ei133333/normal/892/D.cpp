#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N;
  cin >> N;
  vector< pair< int, int > > dat;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    dat.emplace_back(x, i);
  }
  sort(begin(dat), end(dat));
  vector< int > mex(N);
  for(int i = 0; i < N; i++) {
    mex[dat[(i+1)%N].second] = dat[i].first;
  }
  for(int i = 0; i < N; i++) {
    cout << mex[i] << " ";
  }
  cout << endl;
}