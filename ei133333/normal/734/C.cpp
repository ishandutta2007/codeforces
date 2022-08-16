#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, K, X, S;

  cin >> N >> M >> K;
  cin >> X >> S;

  vector< pair< int, int > > A(M), B(K);
  for(int i = 0; i < M; i++) cin >> A[i].second;
  for(int i = 0; i < M; i++) cin >> A[i].first;
  for(int i = 0; i < K; i++) cin >> B[i].second;
  for(int i = 0; i < K; i++) cin >> B[i].first;
  A.emplace_back(0, X);
  B.emplace_back(0, 0);

  sort(begin(A), end(A));
  sort(begin(B), end(B));

  long long ret = numeric_limits< long long >::max();
  int tail = 0, ei = 0;
  for(int i = A.size() - 1; i >= 0; i--) {
    if(A[i].first > S) continue;
    while(tail < B.size() && 0LL + B[tail].first + A[i].first <= S) {
      ei = max(ei, B[tail++].second);
    }
    ret = min(ret, 1LL * A[i].second * max(0, N - ei));
  }
  cout << ret << endl;
}