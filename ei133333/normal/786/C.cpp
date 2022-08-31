#include<bits/stdc++.h>

using namespace std;

int N, A[100000];
int ans[100001];

int beet(int v)
{
  int sum[100001] = {}, last = 0, ret = 1, uku = 0;
  for(int i = 0; i < N; i++) {
    sum[A[i]]++;
    if(sum[A[i]] == 1) ++uku;
    if(uku > v) {
      while(last < i) --sum[A[last++]];
      ++ret;
      uku = 1;
    }
  }
  return (ret);
}


void rec(int l, int r)
{
  while(l < r && ans[l] == ans[r]) ans[++l] = ans[r];
  if(r - l <= 1) return;
  int mid = (l + r) >> 1;
  ans[mid] = beet(mid);
  rec(l, mid);
  rec(mid, r);
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  ans[1] = beet(1);
  ans[N] = beet(N);
  rec(1, N);

  for(int i = 1; i <= N; i++) printf("%d ", ans[i]);
  puts("");
}