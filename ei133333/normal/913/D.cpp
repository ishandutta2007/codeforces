#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N, T;

  scanf("%d %d", &N, &T);
  vector< pair< int, int > > D[200001];
  for(int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    D[x].emplace_back(y, i);
  }

  priority_queue< pair< int, int > > que;
  int64 in = 0;


  for(int i = N; i >= 0; i--) {
    for(auto &p : D[i]) {
      que.emplace(p);
      in += p.first;
    }
    while(que.size() > i) {
      in -= que.top().first;
      que.pop();
    }
    if(que.size() == i && in <= T) {
      printf("%d\n%d\n", i, i);
      while(que.size()) {
        printf("%d ", que.top().second + 1);
        que.pop();
      }
      return (0);
    }
  }
}