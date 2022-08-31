#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, M;
vector< int > sub;
int64 latte[22], malta[22];

void Build(int l, int r, int depth)
{
  if(depth == 0) return;
  int mid = (l + r) >> 1;
  Build(l, mid, depth - 1);
  Build(mid, r, depth - 1);
  vector< int > call;
  for(int i = l; i < mid; i++) call.push_back(sub[i]);
  sort(begin(call), end(call));
  for(int i = mid; i < r; i++) {
    int get1 = upper_bound(begin(call), end(call), sub[i]) - begin(call);
    int get2 = lower_bound(begin(call), end(call), sub[i]) - begin(call);
    latte[depth] += call.size() - get1;
    malta[depth] += get2;
  }
}

int main()
{
  scanf("%d", &N);
  sub.resize(1 << N);
  for(int &a : sub) scanf("%d", &a);
  scanf("%d", &M);
  Build(0, 1 << N, N);
  while(M--) {
    int K;
    scanf("%d", &K);
    for(int j = 1; j <= K; j++) swap(latte[j], malta[j]);
    printf("%lld\n", accumulate(latte, latte + N + 1, 0LL));
  }
}