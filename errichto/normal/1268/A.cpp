#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a) {
  printf("%d\n", (int) a.size());
  for(int x : a) {
    printf("%d", x);
  }
  puts("");
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    a[i] = c - '0';
  }
  vector<int> b = a;
  for(int i = k; i < n; ++i) {
    b[i] = b[i-k];
  }
  if(b >= a) {
    print(b);
    return 0;
  }
  for(int i = k - 1; i >= 0; --i) {
    if(a[i] != 9) {
      a[i]++;
      for(int j = i + 1; j < k; ++j) {
        a[j] = 0;
      }
      for(int j = k; j < n; ++j) {
        a[j] = a[j-k];
      }
      print(a);
      return 0;
    }
  }
  assert(false);
  // k=4
      // 1589
  // 158916..
}