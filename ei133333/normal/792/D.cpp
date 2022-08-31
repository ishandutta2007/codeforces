#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 subtree[65];
string S;

int64 dfs2(int64 depth, int64 shifted, const int64 target, bool right)
{
  int64 mid_number = shifted + subtree[depth - 1];
  if(target == mid_number) {
    if(depth == 1) return (-1);
    if(right) return ((shifted + subtree[depth - 1] + 1) + subtree[depth - 2]);
    return (shifted + subtree[depth - 2]);
  } else if(target < mid_number) {
    return (dfs2(depth - 1, shifted, target, right));
  } else {
    return (dfs2(depth - 1, shifted + subtree[depth - 1] + 1, target, right));
  }
}

int64 dfs(int64 depth, int64 shifted, const int64 target, int64 par = -1LL)
{
  int64 mid_number = shifted + subtree[depth - 1];
  if(target == mid_number) {
    return (par);
  } else if(target < mid_number) {
    return (dfs(depth - 1, shifted, target, mid_number));
  } else {
    return (dfs(depth - 1, shifted + subtree[depth - 1] + 1, target, mid_number));
  }
}

int main()
{

  int64 N, Q;
  cin >> N >> Q;

  int64 Depth = 0, sz = 1;
  while(sz != N + 1) sz <<= 1LL, ++Depth;

  int64 fact = 1;
  for(int i = 0; i <= Depth; i++) {
    subtree[i] = fact - 1;
    fact *= 2;
  }

  while(Q--) {
    int64 U;
    cin >> U;
    cin >> S;

    U--;
    for(int i = 0; i < S.size(); i++) {
      if(S[i] == 'U') {
        auto get = dfs(Depth, 0, U);
        if(~get) U = get;
      } else if(S[i] == 'L') {
        auto get = dfs2(Depth, 0, U, false);
        if(~get) U = get;
      } else {
        auto get = dfs2(Depth, 0, U, true);
        if(~get) U = get;
      }
    }
    cout << U + 1 << endl;
  }
}