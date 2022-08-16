#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main()
{
  int N, S;

  scanf("%d %d", &N, &S);
  int64 ret = 0, need_slice = 0;
  vector< pair< int, int > > d(N), e(N);
  for(int i = 0; i < N; i++) {
    int s, a, b;
    scanf("%d %d %d", &s, &a, &b);
    int rest = min(a, b);
    ret += 1LL * s * min(a, b);
    need_slice += s;
    d[i] = {a - b, s};
    e[i] = {b - a, s};
  }
  sort(d.rbegin(), d.rend());
  sort(e.rbegin(), e.rend());
  int64 free_slice = (need_slice + S - 1) / S * S - need_slice;

  auto solve = [&](vector< pair< int, int > > &a)
  {
    int64 curr = 0, now = 0;
    int last = -1;
    for(int i = 0; i < a.size(); i++) {
      if(a[i].first > 0) {
        curr += 1LL * a[i].first * a[i].second;
        now += a[i].second;
        last = max(last, i);
      }
    }
    now %= S;
    now = (S - now) % S;
    now -= free_slice;
    for(int i = last + 1; i < a.size(); i++) {
      int64 skip = max(0LL, min(now, (int64) a[i].second));
      now -= skip;
      a[i].second -= skip;
      curr += -1LL * a[i].first * a[i].second;
    }
    return (curr);
  };

  cout << ret + max(solve(d), solve(e)) << endl;
}