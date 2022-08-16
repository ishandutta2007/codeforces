#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, Q, V[1003][1003];
  pair< int, int > t[1003][1003], s[1003][1003], l[1003][1003], r[1003][1003];

  scanf("%d %d %d", &N, &M, &Q);
  for(int i = 0; i <= N + 1; i++) {
    for(int j = 0; j <= M + 1; j++) {
      t[i][j] = {i - 1, j};
      s[i][j] = {i + 1, j};
      l[i][j] = {i, j - 1};
      r[i][j] = {i, j + 1};
    }
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      scanf("%d", &V[i][j]);
    }
  }

  queue< pair< pair< int, int >&, pair< int, int >& > > event;
  while(Q--) {
    int a, b, c, d, h, w;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
    pair< int, int > AB(a, 0), CD(c, 0);
    for(int i = 0; i < b; i++) {
      AB = r[AB.first][AB.second];
    }
    for(int i = 0; i < d; i++) {
      CD = r[CD.first][CD.second];
    }
    AB = l[AB.first][AB.second], CD = l[CD.first][CD.second];
    for(int i = 0; i < w; i++) {
      AB = r[AB.first][AB.second];
      CD = r[CD.first][CD.second];
      auto pp = t[AB.first][AB.second], qq = t[CD.first][CD.second];
      event.emplace(s[pp.first][pp.second], s[qq.first][qq.second]);
      event.emplace(t[AB.first][AB.second], t[CD.first][CD.second]);
    }
    AB = t[AB.first][AB.second], CD = t[CD.first][CD.second];
    for(int i = 0; i < h; i++) {
      AB = s[AB.first][AB.second];
      CD = s[CD.first][CD.second];
      auto pp = r[AB.first][AB.second], qq = r[CD.first][CD.second];
      event.emplace(l[pp.first][pp.second], l[qq.first][qq.second]);
      event.emplace(r[AB.first][AB.second], r[CD.first][CD.second]);
    }
    AB = r[AB.first][AB.second], CD = r[CD.first][CD.second];
    for(int i = 0; i < w; i++) {
      AB = l[AB.first][AB.second];
      CD = l[CD.first][CD.second];
      auto pp = s[AB.first][AB.second], qq = s[CD.first][CD.second];
      event.emplace(t[pp.first][pp.second], t[qq.first][qq.second]);
      event.emplace(s[AB.first][AB.second], s[CD.first][CD.second]);
    }
    AB = s[AB.first][AB.second], CD = s[CD.first][CD.second];
    for(int i = 0; i < h; i++) {
      AB = t[AB.first][AB.second];
      CD = t[CD.first][CD.second];
      auto pp = l[AB.first][AB.second], qq = l[CD.first][CD.second];
      event.emplace(r[pp.first][pp.second], r[qq.first][qq.second]);
      event.emplace(l[AB.first][AB.second], l[CD.first][CD.second]);
    }
    while(!event.empty()) {
      swap(event.front().first, event.front().second);
      event.pop();
    }
  }

  for(int i = 1; i <= N; i++) {
    pair< int, int > p(i, 0);
    for(int j = 0; j < M; j++) {
      p = r[p.first][p.second];
      printf("%d ", V[p.first][p.second]);
    }
    puts("");
  }
}