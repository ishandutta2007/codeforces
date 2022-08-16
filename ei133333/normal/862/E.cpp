#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 INF = 1LL << 60;
#define int long long

signed main()
{
  int N, M, Q;
  int A[500000], B[500000];

  scanf("%lld %lld %lld", &N, &M, &Q);
  for(int i = 0; i < N; i++) scanf("%lld", A + i);
  for(int i = 0; i < M; i++) scanf("%lld", B + i);

  int64 all = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) all += A[i];
    else all -= A[i];
  }

  vector< int64 > vs;
  int64 f[2] = {};
  for(int k = 0; k + N <= M; k++) {

    if(k < 2) {
      for(int i = 0; i < N; i++) {
        if(i % 2 == 0) f[k] -= B[i + k];
        else f[k] += B[i + k];
      }
    } else {
      f[k & 1] += B[k - 2];
      f[k & 1] -= B[k - 1];
      if(N % 2 == 0) {
        f[k & 1] -= B[k + N - 2];
        f[k & 1] += B[k + N - 1];
      } else {
        f[k & 1] += B[k + N - 2];
        f[k & 1] -= B[k + N - 1];
      }
    }
    vs.emplace_back(f[k & 1]);
  }

  auto access = [&]()
  {
    all *= -1;
    auto p = lower_bound(begin(vs), end(vs), all);
    int64 ret = INF;
    if(p != end(vs)) ret = min(ret, llabs(*p - all));
    if(p != begin(vs)) ret = min(ret, llabs(all - *prev(p)));
    all *= -1;
    return (ret);
  };

  sort(begin(vs), end(vs));

  printf("%lld\n", access());
  for(int i = 0; i < Q; i++) {
    int a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a % 2 == 1 && b % 2 == 1) all += c;
    else if(a % 2 == 0 && b % 2 == 0) all -= c;
    printf("%lld\n", access());
  }


}