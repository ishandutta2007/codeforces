#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int T, N;

  cin >> T;
  while(T--) {
    cin >> N;
    queue< pair< int, int > > que;
    vector< int > ans(N);
    int now = 0;

    auto sweep = [&](int x)
    {
      while(que.size() && now < x) {
        int idx, tt;
        tie(idx, tt) = que.front();
        que.pop();
        if(now > tt) continue;
        ans[idx] = now;
        ++now;
      }
      now = x;
    };

    for(int i = 0; i < N; i++) {
      int l, r;
      cin >> l >> r;
      sweep(l);
      que.emplace(i, r);
    }
    sweep(13333);

    for(int i = 0; i < N; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}