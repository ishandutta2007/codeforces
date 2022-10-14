#include <bits/stdc++.h>

bool visited[26];
char s[201], buffer[53];

char *solve() {
  memset(visited, 0, sizeof(visited));
  memset(buffer, 0, sizeof(buffer));
  visited[(buffer[26] = s[0]) - 'a'] = true;
  int p = 26;
  for (int i = 1; s[i]; ++i) {
    if (buffer[p - 1] == s[i]) {
      p--;
    } else if (buffer[p + 1] == s[i]) {
      p++;
    } else {
      if (visited[s[i] - 'a']) {
        return nullptr;
      }
      visited[s[i] - 'a'] = true;
      if (!buffer[p + 1]) {
        buffer[++p] = s[i];
      } else if (!buffer[p - 1]) {
        buffer[--p] = s[i];
      } else {
        return nullptr;
      }
    }
  }
  char *q = buffer + 52;
  while (!*q) {
    q--;
  }
  for (int i = 0; i < 26; ++i) {
    if (!visited[i]) {
      *(++q) = 'a' + i;
    }
  }
  q = buffer;
  while (!*q) {
    q++;
  }
  return q;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    auto p = solve();
    if (p == nullptr) {
      puts("NO");
    } else {
      puts("YES");
      puts(p);
    }
  }
}