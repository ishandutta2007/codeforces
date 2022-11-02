#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;

const int maxN = 100000 + 233;
int n, p, k, a[maxN], b[maxN], q[maxN];
LL A[maxN], B[maxN];

bool cmp(int x, int y) {
  return b[x] < b[y] || (b[x] == b[y] && a[x] > a[y]);
}

bool cmp_a(int x, int y) {
  return a[x] > a[y];
}
bool cmp_b(int x, int y) {
  return b[x] > b[y];
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> p >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i], q[i] = i;
  sort(q + 1, q + n + 1, cmp);
  
  LL sum = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i = n; i >= n - k + 1; --i) pq.push(a[q[i]]), sum += a[q[i]];
  A[n - k + 1] = sum;
  for(int i = n - k; i >= 1; --i) {
    pq.push(a[q[i]]); sum += a[q[i]];
    sum -= pq.top(), pq.pop();
    A[i] = sum;
  }
  
  sum = 0;
  priority_queue<int, vector<int>, greater<int> > qp;
  for(int i = 1; i <= p - k; ++i) qp.push(b[q[i]]), sum += b[q[i]];
  B[p - k] = sum;
  for(int i = p - k + 1; i <= n; ++i) {
    qp.push(b[q[i]]); sum += b[q[i]];
    sum -= qp.top(); qp.pop();
    B[i] = sum;
  }
  
  pll ans(-1LL, -1LL); int pos = -1;
  for(int i = p - k; i < n - k + 1; ++i) {
    pll now(A[i + 1], B[i]);
    if(now > ans) ans = now, pos = i;
  }
  cerr << ans.first << " " << ans.second << endl;
  sort(q + 1, q + pos + 1, cmp_b);
  sort(q + pos + 1, q + n + 1, cmp_a);
  for(int i = 1; i <= p - k; ++i) printf("%d ", q[i]);
  for(int i = pos + 1; i <= pos + k; ++i) printf("%d ", q[i]);
  return 0;
}