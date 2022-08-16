#include<bits/stdc++.h>
using namespace std;
#define int long long

int N, A, B, T;
string S;

long long Solve()
{
  int Cost[500000] = {};
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == 'w') Cost[i] = B + 1;
    else Cost[i] = 1;
  }

  if(T - Cost[0] < 0) {
    return(0);
  }
  T -= Cost[0];

  int RightIdx = 0, ret = 1;
#define Prev(k) (k - 1 + S.size()) % S.size()
#define Next(k) (k + 1) % S.size()

  int best = ret;
  while(T - A - Cost[Prev(RightIdx)] >= 0) {
    RightIdx = Prev(RightIdx);
    T -= A;
    T -= Cost[RightIdx];
    ++ret;
    if(ret==N)return(N);
  }

  best = max(best, ret);
  if(ret >= N) {
    return(N);
  }

  for(int i = 1; i < N; i++) {
    while(RightIdx != 0 && T - A - Cost[i] - (N - RightIdx) * A < 0) {
      T += A;
      T += Cost[RightIdx];
      RightIdx = Next(RightIdx);;
      --ret;
    }
    if(T - A - Cost[i] - (N - RightIdx) * A < 0) break;
    T -= A;
    T -= Cost[i];
    ++ret;
    best = max(best, ret);
  }
  return(best);
}

signed main()
{
  cin >> N >> A >> B >> T;
  int Buffer = T;
  cin >> S;
  int res = Solve();
  T = Buffer;
  reverse(S.begin() + 1, S.end());
  cout << max(res, Solve()) << endl;
}