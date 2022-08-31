#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

// ???i????j??????? a_i > a_j(????????)

int main()
{
  int N, W;
  cin >> N >> W;
  vector< pair< int, int > > vs;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    vs.emplace_back(a, i);
  }
  sort(begin(vs), end(vs));

  int ret = 0;
  vector< int > ans(N, 0);
  for(auto &s : vs) {
    int less = (s.first + 1) / 2;
    ans[s.second] += less;
    ret += less;
  }

  if(ret > W) {
    cout << -1 << endl;
    return (0);
  }


  int sa = W - ret;
  reverse(begin(vs), end(vs));
  for(auto &s : vs) {
    int less = (s.first + 1) / 2;
    int zan = s.first - less;
    ans[s.second] += min(zan, sa);
    sa -= min(zan, sa);
  }

  if(sa > 0) {
    cout << -1 << endl;
    return(0);
  }

  for(int i = 0; i < N; i++) cout << ans[i] << " ";
  cout << endl;
}