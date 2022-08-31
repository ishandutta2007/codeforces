#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1 << 30;


int N;
string S[100000];
vector< int > pre[100000];

int64 rec(int idx) {
  int64 pre_match = 0, suf_match = 0;
  while(pre_match < pre[idx].size() && pre[idx][pre_match] == 1) ++pre_match;
  reverse(begin(pre[idx]), end(pre[idx]));
  while(suf_match < pre[idx].size() && pre[idx][suf_match] == 1) ++suf_match;
  reverse(begin(pre[idx]), end(pre[idx]));


  int64 tap = 0, uku = 0;
  while(tap < pre[idx].size()) {
    if(pre[idx][tap] == 0) {
      ++tap;
    } else {
      int cur = tap;
      while(tap < pre[idx].size() && pre[idx][tap] == 1) ++tap;
      uku = max(uku, tap - cur);
    }
  }

  if(idx == 0) {
    return uku;
  } else if(pre_match == pre[idx].size()) {
    auto ret = rec(idx - 1);
    return min(INF, ret + (ret + 1) * (int) pre[idx].size());
  } else {
    auto ret = rec(idx - 1);
    if(ret == 0) return uku;
    return max(uku, 1 + suf_match + pre_match);
  }
}



int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> S[i];

  int64 ret = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    for(int j = 0; j < N; j++) {
      pre[j].resize(S[j].size());
      for(int k = 0; k < S[j].size(); k++) {
        pre[j][k] = S[j][k] == c;
      }
    }
    ret = max(ret, rec(N - 1));
    int64 tap = 0;
    while(tap < pre[N-1].size()) {
      if(pre[N-1][tap] == 0) {
        ++tap;
      } else {
        int64 cur = tap;
        while(tap < pre[N-1].size() && pre[N-1][tap] == 1) ++tap;
        ret = max(ret, tap - cur);
      }
    }
  }
  cout << ret << endl;
}