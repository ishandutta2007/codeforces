#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  int64 L[200000], R[200000];
  cin >> N;
  vector< int64 > vs;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    vs.push_back(L[i] - 1);
    vs.push_back(L[i]);
    vs.push_back(R[i]);
    vs.push_back(R[i] + 1);
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(vs), end(vs), L[i]) - begin(vs);
    R[i] = lower_bound(begin(vs), end(vs), R[i]) - begin(vs);
  }
  vector< int > sum(vs.size());
  for(int i = 0; i < N; i++) {
    sum[L[i]]++;
    sum[R[i] + 1]--;
  }
  int st = 0;
  for(int i = 0; i < vs.size(); i++) {
    st += sum[i];
    sum[i] = st;
  }
  vector< int64 > ans(N + 1);
  for(int i = 0; i + 1 < vs.size(); i++) {
    if(sum[i] > 0) {
      ans[sum[i]] += vs[i + 1] - vs[i];
    }
  }
  for(int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}