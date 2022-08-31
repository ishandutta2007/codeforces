#include<bits/stdc++.h>

using namespace std;

struct Mo
{
  vector< int > left, right, order;
  vector< bool > v;
  int width;
  int nl, nr, ptr;

  Mo(int n) : width((int) sqrt(n)), nl(0), nr(0), ptr(0), v(n) {}

  void insert(int l, int r) /* [l, r) */
  {
    left.push_back(l);
    right.push_back(r);
  }

  /*  */
  void build()
  {
    order.resize(left.size());
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int a, int b)
    {
      if(left[a] / width != left[b] / width) return left[a] < left[b];
      return right[a] < right[b];
    });
  }

  /*  1 , id */
  int process()
  {
    if(ptr == order.size()) return (-1);
    const auto id = order[ptr];
    while(nl > left[id]) addLeft(--nl);
    while(nr < right[id]) addRight(nr++);
    while(nl < left[id]) delLeft(nl++);
    while(nr > right[id]) delRight(--nr);
    return (order[ptr++]);
  }

  void addLeft(int idx);

  void addRight(int idx);

  void delLeft(int idx);

  void delRight(int idx);
};

using int64 = long long;

int N, K, Q;
int T[100000], A[100000];

int64 ans[100000], curr;

int64 sum[100001];
int64 addL[100001], addR[100001];
int64 sz[100001];

void Mo::addLeft(int idx)
{
  if(~addL[idx]) curr += sz[addL[idx]];
  ++sz[sum[idx]];
}

void Mo::addRight(int idx)
{
  if(~addR[idx]) curr += sz[addR[idx]];
  ++sz[sum[idx]];
}


void Mo::delLeft(int idx)
{
  --sz[sum[idx]];
  if(~addL[idx]) curr -= sz[addL[idx]];
}

void Mo::delRight(int idx)
{
  --sz[sum[idx]];
  if(~addR[idx]) curr -= sz[addR[idx]];
}

int main()
{

  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if(T[i] == 2) A[i] *= -1;
  }

  for(int i = 0; i < N; i++) {
    sum[i + 1] = A[i] + sum[i];
  }
  vector< int64 > vs;
  for(int i = 0; i <= N; i++) {
    vs.emplace_back(sum[i]);
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  memset(addL, -1, sizeof(addL));
  memset(addR, -1, sizeof(addR));
  for(int i = 0; i <= N; i++) {
    auto p = lower_bound(begin(vs), end(vs), sum[i] + K);
    auto q = lower_bound(begin(vs), end(vs), sum[i] - K);
    sum[i] = lower_bound(begin(vs), end(vs), sum[i]) - begin(vs);
    if(p != end(vs) && *p == vs[sum[i]] + K) addL[i] = p - begin(vs);
    if(*q == vs[sum[i]] - K) addR[i] = q - begin(vs);
  }

  scanf("%d", &Q);
  Mo mo(N+1);
  for(int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    mo.insert(--l, r+1);
  }
  mo.build();
  for(int i = 0; i < Q; i++) {
    ans[mo.process()] = curr;
  }
  for(int i = 0; i < Q; i++) {
    printf("%lld\n", ans[i]);
  }
}