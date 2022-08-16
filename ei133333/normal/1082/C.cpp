#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int N, M;
  cin >> N >> M;
  vector< int > beet[100000];
  for(int i = 0; i < N; i++) {
    int s, r;
    cin >> s >> r;
    --s;
    beet[s].push_back(r);
  }
  vector< int > exists;
  for(int i = 0; i < M; i++) {
    sort(begin(beet[i]), end(beet[i]));
    if(beet[i].size()) exists.push_back(i);
  }
  int64 sum[100000] = {};

  int64 ret = 0;
  while(exists.size()) {
    vector< int > next_exists;
    int64 sub = 0;
    for(auto &p : exists) {
      sum[p] += beet[p].back();
      sub += max(0LL, sum[p]);
      beet[p].pop_back();
      if(beet[p].size()) next_exists.push_back(p);
    }
    ret = max(ret, sub);
    exists.swap(next_exists);
  }

  cout << ret << endl;
}