#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

int LCP1[2200][2200];
int LCP2[2200][2200];

int main()
{
  string S, T, W;

  cin >> S;
  T = S;
  reverse(T.begin(), T.end());
  cin >> W;

  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = W.size() - 1; j >= 0; j--) {
      LCP1[i][j] = S[i] == W[j] ? LCP1[i + 1][j + 1] + 1 : 0;
    }
  }
  for(int i = T.size() - 1; i >= 0; i--) {
    for(int j = W.size() - 1; j >= 0; j--) {
      LCP2[i][j] = T[i] == W[j] ? LCP2[i + 1][j + 1] + 1 : 0;
    }
  }

  vector< pair< int, int > > hoge;
  int ret = 0;

  for(int i = 0; i < W.size(); ) {
    pair< int, int > pos(0, INF);
    for(int j = 0; j < S.size(); j++) {
      pos = max(pos, {LCP1[j][i], j + 1});
    }
    for(int j = 0; j < S.size(); j++) {
      pos = max(pos, {LCP2[j][i], j - S.size()});
    }
    if(pos.first == 0) {
      cout << -1 << endl;
      exit(0);
    }
    ++ret;
    if(pos.second > 0) hoge.push_back({pos.second, pos.first + pos.second - 1});
    else hoge.push_back({-pos.second, -pos.second - pos.first + 1});
    i = i + pos.first; 
  }
  cout << ret << endl;
  for(int i = 0; i < hoge.size(); i++) {
    cout << hoge[i].first << " " << hoge[i].second << endl;
  }
}