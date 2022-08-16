#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int N, H, W;
  int A[100000], B[100000], C[100000], D[100000];

  cin >> N;
  cin >> W >> H;

  vector< int > aaa(W + 1, 0), bbb(H + 1, 0), ccc(W + 1, 0), ddd(H + 1, 0);
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    if(A[i] > C[i]) swap(A[i], C[i]);
    if(B[i] > D[i]) swap(B[i], D[i]);
    if(B[i] == D[i]) aaa[A[i]]++, bbb[B[i]]++;
    else ccc[A[i]]++, ddd[B[i]]++;
  }
  for(int i = 1; i <= W; i++) aaa[i] += aaa[i - 1];
  for(int i = 1; i <= H; i++) bbb[i] += bbb[i - 1];
  for(int i = 1; i <= W; i++) ccc[i] += ccc[i - 1];
  for(int i = 1; i <= H; i++) ddd[i] += ddd[i - 1];


  int l, r, t, b;
  cin >> l >> r >> t >> b;
  for(int i = 0; i < N; i++) {
    int left = 0, right = 0, top = 0, bottom = 0;
    if(B[i] == D[i]) {
      left += aaa[A[i]];
      left += ccc[A[i]];
      --left;
      right += aaa[W] - aaa[A[i] - 1];
      right += ccc[W] - ccc[A[i]];
      --right;
      top += bbb[B[i] - 1];
      top += ddd[B[i] - 1];
      bottom += bbb[H] - bbb[B[i]];
      bottom += ddd[H] - ddd[B[i] - 1];
    } else {
      top += ddd[B[i]];
      top += bbb[B[i]];
      --top;
      bottom += ddd[H] - ddd[B[i] - 1];
      bottom += bbb[H] - bbb[B[i]];
      --bottom;
      left += ccc[A[i] - 1];
      left += aaa[A[i] - 1];
      right += ccc[W] - ccc[A[i]];
      right += aaa[W] - aaa[A[i] - 1];
    }
    if(l == left && r == right && top == t && bottom == b) {
      cout << i + 1 << endl;
      return;
    }
  }

  cout << -1 << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}