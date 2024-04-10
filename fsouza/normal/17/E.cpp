#include <iostream>
#include <cstdio>

#define MAXN 2000010

typedef long long lint;
typedef unsigned long long ulint;

using namespace std;

const lint mod = 51123987, inv2 = (mod+1)/2;
const lint base = 33;

int n;

char input[MAXN+1];
lint start[MAXN+1], end[MAXN+1];

ulint phash[MAXN+1], shash[MAXN+1], bpow[MAXN+2];
/*      [0,x)           [x,n) */

ulint hashit(lint a, lint b)
{
  return phash[b+1] - phash[a] * bpow[b+1-a];
}

ulint revhashit(lint a, lint b)
{
  return shash[a] - shash[b+1] * bpow[b+1-a];
}

void odd(int i)
{
  int left = 0, right = min(i, n-1-i);
  
  while (left < right) {
    int m = (left+right+1)/2;

    if (hashit(i-m, i+m) == revhashit(i-m, i+m))
      left = m;
    else
      right = m-1;
  }

  start[i-left] ++;
  start[i+1] --;
  
  end[i]++;
  end[i+left+1]--;
}

void even(int i)
{
  int left = 0, right = min(i, n-1-(i+1));

  while (left < right) {
    int m = (left+right+1)/2;

    if (hashit(i-m, i+1+m) == revhashit(i-m, i+1+m))
      left = m;
    else
      right = m-1;
  }

  start[i-left] ++;
  start[i+1] --;

  end[i+1] ++;
  end[i+1+left+1]--;
}

void calc_start_end()
{
  for (int i = 0; i < n; i++)
    odd(i);
  for (int i = 0; i+1 < n; i++)
    if (input[i] == input[i+1])
      even(i);

  for (int i = 1; i <= n; i++) {
    start[i] += start[i-1];
    end[i] += end[i-1];
    start[i] %= mod;
    end[i] %= mod;
    start[i] = (start[i]+mod)%mod;
    end[i] = (end[i]+mod)%mod;
  }

  start[0] = (start[0]%mod + mod)%mod;
  end[0] = (end[0]%mod + mod)%mod;
}

int main()
{
  bpow[0] = 1;
  for (int i = 1; i < MAXN+2; i++)
    bpow[i] = base*bpow[i-1];

  scanf("%d", &n);
  scanf(" %s", input);

  phash[0] = 0;
  for (int i = 0; i < n; i++)
    phash[i+1] = phash[i]*base + input[i]-'a';

  shash[n] = 0;
  for (int i = n-1; i >= 0; i--)
    shash[i] = shash[i+1]*base + input[i]-'a';

  calc_start_end();

  lint ret = 0;

  lint ssum = 0;
  for (int i = 0; i < n; i++) {
    ret = ret - start[i]*(start[i]-1)%mod*inv2%mod - start[i];
    while (ret < 0) ret += mod;
    ssum = ssum+start[i];
    if (ssum >= mod) ssum -= mod;
    ret = (ret + end[i]*ssum)%mod;
    ret = ret - start[i+1]*ssum%mod;
    if (ret < 0) ret += mod;
  }

  printf("%lld\n", ret);

  return 0;
}