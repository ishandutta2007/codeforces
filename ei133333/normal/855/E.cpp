#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 dp[70][1 << 10][10][2];
string S;

int64 rec(int idx, int bit, bool free, int zero, const int bb)
{
  if(idx == -1) return (bit == 0);
  if(free && ~dp[idx][bit][bb][zero]) return (dp[idx][bit][bb][zero]);
  int end = free ? bb - 1 : S[idx] - '0';
  int64 ret = 0;
  for(int i = 0; i <= end; i++) {
    bool nt = zero & (i == 0);
    ret += rec(idx - 1, nt ? 0 : (bit ^ (1 << i)), free | (i != end), nt, bb);
  }
  if(free) return (dp[idx][bit][bb][zero] = ret);
  return (ret);
}

int main()
{
  memset(dp, -1, sizeof(dp));

  int Q;
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int B;
    int64 L, R;
    scanf("%d %lld %lld", &B, &L, &R);

    S.clear();
    --L;
    do {
      S += char('0' + L % B);
      L /= B;
    } while(L);

    auto ret = -rec(S.size() - 1, 0, false, true, B);

    S.clear();
    do {
      S += char('0' + R %B);
      R /= B;
    } while(R);
    ret += rec(S.size() - 1, 0, false, true, B);
    printf("%lld\n", ret);
  }
}