#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

template< typename T >
struct SparseTable
{
  vector< vector< T > > st;

  SparseTable() {}

  SparseTable(const vector< T > &v)
  {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  inline T rmq(int l, int r) // [l, r)
  {
    int b = 32 - __builtin_clz(r - l) - 1;
    return (min(st[b][l], st[b][r - (1 << b)]));
  }
};

int N, P, A[194598];
int d[5032109];
int latte[5032109][8];

int main() {

  fill_n(*latte, 5032109 * 8, INF);
  for(int i = 1; i <= 5032108; i++) d[i] = i;
  for(int i = 2; i * i <= 5032108; i++) {
    if(d[i] != i) continue;
    for(int j = i + i; j <= 5032108; j += i) d[j] = min(d[j], i);
  }

  scanf("%d %d", &N, &P);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  vector< vector< int > > dp(15, vector< int >(N, INF));
  for(int i = N - 1; i >= 0; i--) {
    set< int > st;
    while(A[i] != 1) {
      if(st.count(d[A[i]])) st.erase(d[A[i]]);
      else st.emplace(d[A[i]]);
      A[i] /= d[A[i]];
    }
    vector< int > uku;
    for(auto &p : st) uku.emplace_back(p);

    for(int j = 0; j < (1 << uku.size()); j++) {
      int mul = 1, add = 0;
      for(int k = 0; k < uku.size(); k++) {
        if((j >> k) & 1) mul *= uku[k];
        else ++add;
      }
      for(int k = 0; k < 8; k++) {
        dp[k + add][i] = min(dp[k + add][i], latte[mul][k]);
      }
    }

    for(int j = 0; j < (1 << uku.size()); j++) {
      int add = 0, mul = 1;
      for(int k = 0; k < uku.size(); k++) {
        if((j >> k) & 1) mul *= uku[k];
        else ++add;
      }
      latte[mul][add] = i;
    }
  }

  auto f = [&](int a, int b) { return min(a, b); };
  vector< SparseTable< int > > seg;
  for(int i = 0; i < 15; i++) {
    seg.emplace_back(SparseTable< int >(dp[i]));
  }

  for(int i = 0; i < P; i++) {
    int L, R;
    scanf("%d %d", &L, &R);
    --L;
    for(int j = 0; j < 15; j++) {
      if(seg[j].rmq(L, R) < R) {
        printf("%d\n", j);
        break;
      }
    }
  }

}