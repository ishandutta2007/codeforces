#include <bits/stdc++.h>

const int N = 500;

int n, m;
char s[N + 2];

char improve(char c) { return (c == 'a' || c == 'a' + m - 1) ? 'a' : c - 1; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%s", &n, &m, s);
    bool changed = false;
    s[n] = s[n + 1] = 'z';
    // cedk
    // bEDK
    // bceK
    // bcea
    for (int i = 0; i + 1 < n; ++i) {
      char a = s[i];
      char b = s[i + 1];
      char c = s[i + 2];
      if (changed) {
        // a B C
        // b a c
        // c a b
        if (c < a && c < b) {
          // c a b
          s[i] = c;
          s[i + 1] = a;
          s[i + 2] = b;
          i++;
        } else if (b < a) {
          // b a C
          s[i] = b;
          s[i + 1] = a;
        } else {
          // a B C
          changed = false;
        }
      } else {
        changed = true;
        // a' B  C
        // b' a  C
        // b  a' C
        // c  a' b
        if (c < improve(a) && c < improve(b)) {
          // c a' b
          s[i] = c;
          s[i + 1] = improve(a);
          s[i + 2] = b;
          i++;
        } else if (improve(b) < improve(a)) {
          // b' a C
          if (improve(b) == b) {
            s[i] = b;
            s[i + 1] = improve(a);
          } else {
            s[i] = improve(b);
            s[i + 1] = a;
          }
        } else {
          s[i] = improve(a);
          changed = false;
        }
      }
    }
    if (!changed) {
      s[n - 1] = improve(s[n - 1]);
    }
    s[n] = '\0';
    puts(s);
  }
}