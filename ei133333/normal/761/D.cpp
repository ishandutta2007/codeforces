#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, L, R, A[100000], C[100000];

  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) {
    cin >> C[i];
    C[i] = N - C[i];
  }

  vector< int > idx(N);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int &a, int &b)
  {
    return (C[a] < C[b]);
  });


  vector< int64 > B(N), Cc(N);
  int64 prev_C = -1145141919810LL;
  int64 now_value = R;

  for(int i : idx) {
    int64 need_C = prev_C + 1;
    int64 need_B = A[i] - need_C;
    need_B = min(need_B, R);
    if(need_B < L) {
      cout << -1 << endl;
      return(0);
    }
    B[i] = need_B;
    Cc[i] = prev_C = A[i] - B[i];
  }

  for(int i = 0; i < N; i++) {
    if(A[i] - B[i] != Cc[i]) {
      cout << -1 << endl;
      return (0);
    }
  }

  sort(begin(Cc), end(Cc));
  Cc.erase(unique(begin(Cc), end(Cc)), end(Cc));
  if(Cc.size() != N) {
    cout << -1 << endl;
    return (0);
  }

  for(int64 v : B) cout << v << " ";
  cout << endl;
}