#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 110;
const int P = 1000000007;

int m;

struct Mat {
  int g[N][N];
  
  Mat () { memset(g, 0, sizeof(g)); }
  
  int* operator[](int k) { return g[k]; }
  const int* operator[](int k) const { return g[k]; }
  
  
  Mat operator*(const Mat& rhs) const {
    Mat ret = Mat();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < m; ++j)
        for (int k = 0; k < m; ++k) {
          ret[i][j] = (ret[i][j] + g[i][k] * (ll)rhs[k][j]) % P;
        }
    return ret;
  }
};

// f(n): 1 * 1, 1 * m

int main() {
  ll n;
  scanf("%lld%d", &n, &m);
  Mat a = Mat(), ans = Mat();
  for (int i = 0; i < m; ++i)
    ans[i][i] = 1;
  for (int i = 1; i < m; ++i)
    a[i][i - 1] = 1;
  a[0][m - 1] = 1;
  a[m - 1][m - 1] = 1;
  while (n) {
    if (n & 1)
      ans = ans * a;
    if (n >>= 1)
      a = a * a;
  }
  printf("%d\n", ans[m - 1][m - 1]);
  return 0;
}