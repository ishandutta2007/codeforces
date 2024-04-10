#include<bits/stdc++.h>
using namespace std;
const int V = 1.6e7;
int f[V+1];
int cnt[V+1];
const int MAXN = 4e5;
int N;
int A[MAXN];

int main() {
  for (int i = 2; i <= V; i++) {
    if (f[i]) continue;
    for (int j = i; j <= V; j+=i) f[j] = i;
  }
  scanf("%d",&N);
  int g = 0;
  for (int i = 0; i < N; i++) scanf("%d", &A[i]), g=__gcd(g, A[i]);
  int res = 0;
  for (int i = 0; i < N; i++) {
    A[i] /= g;
    while (A[i] > 1) {
      int p = f[A[i]]; while (A[i] % p == 0) A[i] /= p;
      res = max(res, ++cnt[p]);
    }
  }
  cout << (res ? N-res : -1) << '\n';
}