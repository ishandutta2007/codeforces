#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int INF = 1 << 30;

int solve(int w, int h, int64 aa, int64 bb, vector< int64 > &extend)
{
  int mid = (int) extend.size() / 2;
  vector< pair< int64, int64 > > beet;
  int ret = INF;
  for(int i = 0; i <= mid; i++) {
    for(int j = 0; j < (1 << i); j++) {
      int64 a = h, b = w;
      for(int k = 0; k < i; k++) {
        if((j >> k) & 1) b *= extend[k];
        else a *= extend[k];
        a = min(a, aa), b = min(b, bb);
      }
      if(a >= aa && b >= bb) {
        ret = min(ret, i);
      }
      if(i == mid) beet.emplace_back(a, b);
    }
  }
  sort(begin(beet), end(beet));
  for(int i = (int)beet.size() - 2; i >= 0; i--) beet[i].second=max(beet[i].second, beet[i + 1].second);
  int other = (int) extend.size() - mid;
  for(int i = 0; i <= other; i++) {
    for(int j = 0; j < (1 << i); j++) {
      int64 a = 1, b = 1;
      for(int k = 0; k < i; k++) {
        if((j >> k) & 1) b *= extend[mid + k];
        else a *= extend[mid + k];
        a = min(a, aa), b = min(b, bb);
      }
      auto latte = lower_bound(begin(beet), end(beet), make_pair((aa + a - 1) / a, 0LL));
      if(latte == end(beet)) continue;
      if(latte->second * b >= bb) ret = min(ret, i + mid);
    }
  }
  return (ret);
}

int main()
{
  int A, B, H, W, N;
  cin >> A >> B >> H >> W >> N;
  vector< int64 > extend(N);
  for(int i = 0; i < N; i++) cin >> extend[i];
  sort(extend.rbegin(), extend.rend());
  while(extend.size() > 34) extend.pop_back();
  auto get = min(solve(W, H, A, B, extend), solve(H, W, A, B, extend));
  if(get == INF) cout << -1 << endl;
  else cout << get << endl;
}