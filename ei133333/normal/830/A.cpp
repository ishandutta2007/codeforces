#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 INF = 1LL << 59;

int main()
{
  int64 N, K, P, A[1000], B[2000];
  cin >> N >> K >> P;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < K; i++) cin >> B[i];
  sort(A, A + N);
  sort(B, B + K);
  vector< int64 > cur(K, 0LL);
  for(int j = 0; j < K; j++) {
    cur[j] = llabs(A[0] - B[j]) + llabs(B[j] - P);
  }
  for(int i = 1; i < N; i++) {
    vector< int64 > nxt(K, INF);
    int64 sm = INF;
    for(int j = 0; j < K; j++) {
      nxt[j] = max(sm, llabs(A[i] - B[j]) + llabs(B[j] - P));
      sm = min(sm, cur[j]);
    }
    cur.swap(nxt);
  }
  cout << *min_element(begin(cur), end(cur)) << endl;
}