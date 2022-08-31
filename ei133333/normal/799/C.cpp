#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > Pi;

int get(vector< pair< int, int > > &st, int lim)
{
  priority_queue< Pi > que;
  int ret = 0;
  for(auto &s : st) {
    while(!que.empty() && s.first + que.top().second > lim) que.pop();
    if(!que.empty()) ret = max(ret, s.second + que.top().first);
    que.emplace(s.second, s.first);
  }
  return (ret);
}

int main()
{
  int N, C, D;
  vector< Pi > qual[2];

  cin >> N >> C >> D;
  for(int i = 0; i < N; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    qual[c == 'D'].emplace_back(b, a);
  }
  sort(begin(qual[0]), end(qual[0]));
  sort(begin(qual[1]), end(qual[1]));
  while(!qual[0].empty() && qual[0].back().first > C) qual[0].pop_back();
  while(!qual[1].empty() && qual[1].back().first > D) qual[1].pop_back();
  int ret = 0;
  if(!qual[0].empty() && !qual[1].empty()) {
    int latte = 0, malta = 0;
    for(auto &p : qual[0]) latte = max(latte, p.second);
    for(auto &p : qual[1]) malta = max(malta, p.second);
    ret = max(ret, latte + malta);
  }
  ret = max(ret, get(qual[0], C));
  ret = max(ret, get(qual[1], D));
  cout << ret << endl;
}