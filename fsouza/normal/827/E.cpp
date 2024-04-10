#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef unsigned int uint;

// Code for our ACM-ICPC team's notebook.
typedef complex<long double> doublex;
struct FFT {
  vector<doublex> fft(vector<doublex> y, bool invert = false) {
    const int N = y.size(); assert(N == (N&-N));
    vector<int> rev(N);
    for (int i = 1; i < N; ++i) {
      rev[i] = (rev[i>>1]>>1) | (i&1 ? N>>1 : 0);
      if (rev[i] < i) swap(y[i], y[rev[i]]);
    }
    vector<doublex> rootni(N/2);
    for (int n = 2; n <= N; n *= 2) {
      const doublex rootn = polar(1.0, (invert ? +1.0 : -1.0) * 2.0*acos(-1.0)/n);
      rootni[0] = 1.0;
      for (int i = 1; i < n/2; ++i) rootni[i] = rootni[i-1] * rootn;
      for (int left = 0; left != N; left += n) {
	const int mid = left + n/2;
	for (int i = 0; i < n/2; ++i) {
	  const doublex temp = rootni[i] * y[mid + i];
	  y[mid + i] = y[left + i] - temp; y[left + i] += temp;
	}
      }
    } if (invert) for (auto &v : y) v /= (doublex)N;
    return move(y);
  }
  uint nextpow2(uint v) { return v ? 1 << __lg(2*v-1) : 1; }
  vector<doublex> convolution(vector<doublex> a, vector<doublex> b) {
    const int n = max((int)a.size()+(int)b.size()-1, 0), n2 = nextpow2(n);
    a.resize(n2); b.resize(n2);
    vector<doublex> fa = fft(move(a)), fb = fft(move(b)), &fc = fa;
    for (int i = 0; i < n2; ++i) fc[i] = fc[i] * fb[i];
    vector<doublex> c = fft(move(fc), true);
    c.resize(n);
    return move(c);
  }
} fft;
//

vector<int> convolute_rev(vector<int> a, vector<int> b) {
  reverse(b.begin(), b.end());
  vector<doublex> a2(a.begin(), a.end());
  vector<doublex> b2(b.begin(), b.end());
  vector<doublex> result = fft.convolution(a2, b2);
  vector<int> result_int(result.size());
  for (int i = 0; i < (int)result.size(); ++i)
    result_int[i] = (int)round(abs(result[i]));
  return result_int;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    string str(n, ' ');
    scanf("%s", &str[0]);
    vector<int> vs(n, 0), ks(n, 0);
    for (int i = 0; i < n; ++i) {
      if (str[i] == 'V')
        vs[i] = 1;
      else if (str[i] == 'K')
        ks[i] = 1;
    }
    vector<int> conv_vk = convolute_rev(vs, ks);
    vector<bool> dist_vk(n);
    for (int i = 0; i < (int)conv_vk.size(); ++i) {
      const int dist = abs(i - (n - 1));
      if (conv_vk[i]) dist_vk[dist] = true;
    }
    vector<bool> valid(n + 1, true);;
    for (int i = 1; i <= n; ++i)
      for (int j = i; j < n; j += i)
        if (dist_vk[j])
          valid[i] = false;
    vector<int> result;
    for (int i = 1; i <= n; ++i)
      if (valid[i])
        result.push_back(i);
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i]);
    }
    printf("\n");
  }
  return 0;
}