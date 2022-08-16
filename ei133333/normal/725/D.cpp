#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define int long long

int N;
int64 T[300000], W[300000];
vector< pair< int64, int > > lowidx;

int check()
{
  priority_queue< int64, vector< int64 >, greater< int64 > > highdist;
  for(int i = 1; i < N; i++) {
    if(T[0] < T[i]) highdist.push(W[i] - T[i] + 1);
  }
  int ret = highdist.size() + 1, tail = 0;
  int64 odd = T[0];
  while(!highdist.empty()) {
    int64 val = highdist.top();
    highdist.pop();
    odd -= val;
    if(odd < 0) return (ret);
    while(tail < lowidx.size() && odd < lowidx[tail].first) {
      highdist.push(lowidx[tail].second);
      ++tail;
    }
    ret = min< int >(ret, highdist.size() + 1);
  }
  return (ret);
}

signed main()
{
  scanf("%lld", &N);
  for(int i = 0; i < N; i++) {
    scanf("%lld %lld", &T[i], &W[i]);
  }
  for(int i = 1; i < N; i++) {
    if(T[0] >= T[i]) lowidx.emplace_back(T[i], W[i] - T[i] + 1);
  }
  sort(begin(lowidx), end(lowidx));
  reverse(begin(lowidx), end(lowidx));
  printf("%lld\n", check());
}