#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PDD pair<double, double>
#define PSS pair<string, string>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define prev eruyvuy
#define INF 1000000007
#define next abc
const double EPS = 1E-12;
const double PI = acos(-1.0);
const LL mod = 1000000007;

using namespace std;

LL a;
vector<LL> p;
map<LL, vector<int> > vp;
set<PLL> cand;
vector<LL> divs;

int dp[7100][2100];

vector<LL> pr;
vector<vector<LL> > opt;

void ck(LL x) {
  if (x <= 2) return;
  x--;

  if (vp.find(x) != vp.end()) {
    FOR(i, vp[x].size())
      cand.insert(MP(p[vp[x][i]], x));
  } else if (x > 1000005) {
    FOR(i, p.size()) {
      if (x % p[i] == 0)
        return;
    }
    cand.insert(MP(x, x));
  }
}


// X is some divisor of A, and idx is index of the prime number that we should
// start with.
// For test case 27, there are 1638 eligible primes, so dp.size() is 1638.
// For each idx, opt[idx] contains values 1+p[idx]^k such that 1+p[idx]^k is
// a divisor of A. Typically opt[idx] is 1. The total size of all opt[i] for
// test case 27 is 1652.
//
// As a result, total dp size is bounded by num_divisors(A) * num_eligible_primes,
// giving a bound of 7K * 2K = 14M, with number of operations being roughly that,
// as opt[i] is very small on average. This should pass within a second.
inline int go(const LL x, const int idx) {
  if (x == 1)
    return 1;
  if (x == 2)
    return 0;
  if (opt.size() == idx)
    return 0;
 
  int x_idx = lower_bound(divs.begin(), divs.end(), x) - divs.begin();
  int& ans = dp[x_idx][idx];
  if (ans != -1) {
    //cout << "F" << endl;
    return ans;
  }

  ans = go(x, idx+1);
  FOR(i, opt[idx].size()) {
    if (x % (opt[idx][i] + 1) == 0) {
      ans += go(x / (opt[idx][i]+1), idx+1);
    }
  }
  return ans;
}

int main() {
  memset(dp,-1,sizeof(dp));
  ios_base::sync_with_stdio(0);
  int n = 1000005;
  vector<char> prime (n+1, true);
  prime[0] = prime[1] = false;
  for (int i=2; i<=n; ++i)
    if (prime[i])
      if (i * 1ll * i <= n)
        for (int j=i*i; j<=n; j+=i)
          prime[j] = false;
  FOR(i, prime.size())
  if (prime[i]) p.push_back(i);

  cin >> a;
  if (a == 1) {
    cout << 1 << endl;
    return 0;
  }

  FOR(i, p.size()) {
    LL pw = p[i];
    while (pw < a) {
      vp[pw].push_back(i);
      pw *= p[i];
    }
  }

  LL rt = sqrt(a);
  if (rt*rt < a) rt++;
  for (LL i = 1; i <= rt; i++) {
    if (a % i == 0) {
      if (i != a/i) divs.push_back(a/i);
      divs.push_back(i);
      ck(i);
      ck(a/i);
    }
  }

  sort(divs.begin(), divs.end());
  set<PLL>::iterator it = cand.begin();

  while (it != cand.end()) {
    if (pr.size() == 0 || pr.back() != it->first) {
      pr.push_back(it->first);
      vector<LL> aaa;
      aaa.push_back(it->second);
      opt.push_back(aaa);
    } else {
      opt.back().push_back(it->second);
    }
    it++;
  }

  // STILL 1.3 seconds left before this call
  cout << go(a, 0) << endl;

  return 0;
}