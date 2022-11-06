#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

const int maxn = 100;
const int maxp = 607;
const int nsmall = 10;
const int np = maxn + nsmall + 1;

vector<int> prime;
bool isprime[maxp+1], good[maxp+1];
int primeid[maxp+1], mask[maxp+1];
vector<int> goodv;
int dp[maxn+1][1<<nsmall][np+1];

int main() {
  isprime[0] = isprime[1] = false;
  good[1] = true;
  mask[1] = 0;
  for (int i = 2; i <= maxp; i++) {
    isprime[i] = good[i] = true;
    mask[i] = 0;
  }

  for (int i = 2; i <= maxp; i++)
    if (isprime[i]) {
      primeid[i] = prime.size();
      prime.push_back(i);
      if (i > 30)
	good[i] = false;
      else
	mask[i] |= 1 << primeid[i];
      for (int j = i+i; j <= maxp; j += i) {
	isprime[j] = false;
	if (i > 30)
	  good[j] = false;
	else
	  mask[j] |= 1 << primeid[i];
      }
    }

  for (int i = 1; i <= maxp; i++)
    if (good[i])
      goodv.push_back(i);

  int n;
  scanf("%d", &n);
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  memset(dp, 0x3F, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));

  for (int i = 0; i < n; i++)
    for (int s = 0; s < (1<<nsmall); s++)
      for (int nextp = nsmall; nextp < min(np, nsmall+(n-1-i)+1); nextp++) {
	int &res = dp[i+1][s][nextp];
	
	for (int j = 0; j < (int)goodv.size() && goodv[j] <= prime[nextp]; j++) {
	  const int v = goodv[j];
	  if ((s | mask[v]) == s)
	    res = min(res, abs(v - a[i]) + dp[i][s - mask[v]][nextp]);
	}
	res = min(res, abs(prime[nextp] - a[i]) + dp[i][s][nextp+1]);
      }
  
  vector<int> result(n);

  int s = (1<<nsmall)-1, nextp = nsmall;

  for (int i = n-1; i >= 0; i--) {
    int &res = dp[i+1][s][nextp];
	
    for (int j = 0; j < (int)goodv.size() && goodv[j] <= prime[nextp]; j++) {
      const int v = goodv[j];
      if ((s | mask[v]) == s && abs(v - a[i]) + dp[i][s - mask[v]][nextp] == res) {
	s -= mask[v];
	result[i] = v;
	goto next;
      }
    }
    result[i] = prime[nextp];
    nextp++;
  next:
    ;
  }

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}