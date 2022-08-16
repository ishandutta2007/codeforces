#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, M;
  vector< int > ev[200000];

  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    ev[x].emplace_back(y);
    ev[y].emplace_back(x);
  }

  set< int > rest;
  for(int i = 0; i < N; i++) {
    ev[i].emplace_back(-1);
    ev[i].emplace_back(N);
    sort(begin(ev[i]), end(ev[i]));
    rest.emplace(i);
  }
  rest.emplace(13333333);
  vector< int > sz;
  for(int i = 0; i < N; i++) {
    if(rest.count(i) == 0) continue;
    queue< int > que;
    que.emplace(i);
    rest.erase(i);
    sz.emplace_back(0);
    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      sz.back()++;
      for(int j = 1; j < ev[idx].size(); j++) {
        const int L = ev[idx][j - 1] + 1;
        const int R = ev[idx][j] - 1;
        auto ptr = rest.lower_bound(L);
        while(*ptr <= R) {
          que.emplace(*ptr);
          ptr = rest.erase(ptr);
        }
      }
    }
  }

  sort(begin(sz), end(sz));
  printf("%d\n", (int) sz.size());
  for(int i = 0; i < sz.size(); i++) {
    printf("%d ", sz[i]);
  }
  puts("");
}