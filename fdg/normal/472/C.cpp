#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int p[100005];
string f[100005], s[100005];
char str1[55], str2[55];

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %s\n", str1, str2);
    f[i] = str1; s[i] = str2;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]); --p[i];
  }
  string last = "";
  for (int i = 0; i < n; ++i) {
    int ind = p[i];
    bool ls = f[ind] < s[ind];
    if (ls) {
      if (last < f[ind]) last = f[ind];
      else if (last < s[ind]) last = s[ind];
      else {
        puts("NO");
        return 0;
      }
    } else {
      if (last < s[ind]) last = s[ind];
      else if (last < f[ind]) last = f[ind];
      else {
        puts("NO");
        return 0;
      }
    }
  } 
  puts("YES");
  return 0;
}