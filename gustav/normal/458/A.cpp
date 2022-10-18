#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

#define MAX 100005

char a[MAX]; int na;
char b[MAX]; int nb;
int n;

void pad(char *s, int nn) {
  int n = strlen(s);
  for (int i = nn - 1; i >= nn - n; --i) s[i] = s[i - nn + n];
  for (int i = 0; i < nn - n; ++i) s[i] = '0';
}

bool pull(char *s, int i) {
  if (i >= n) return false;
  if (s[i] == '1') return true;
  if (!pull(s, i + 1) || !pull(s, i + 2)) return false;
  s[i] = '1';
  s[i + 1] = '0';
  s[i + 2] = '0';
  return true;
}

int main(void)
{
  scanf("%s", a); na = strlen(a);
  scanf("%s", b); nb = strlen(b);

  n = max(na, nb);
  pad(a, n);
  pad(b, n);

  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) 
      continue;

    if (a[i] == '0' && b[i] == '1') {
      if (!pull(a, i)) {
        puts("<");
        return 0;
      }
      a[i + 1] = '0';
      a[i + 2] = '0';
      continue;
    }

    if (a[i] == '1' && b[i] == '0') {
      if (!pull(b, i)) {
        puts(">");
        return 0;
      }
      b[i + 1] = '0';
      b[i + 2] = '0';
      continue;
    }
  }

  puts("=");

  return 0;
}