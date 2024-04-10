#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, manacher[N + N], result[N >> 1], queue[N >> 1];
char buffer[N + 1], s[N + N];

int end(int i) { return i + manacher[i]; }

int main() {
  scanf("%d%s", &n, buffer);
  for (int i = 0; i < n; ++i) {
    s[i << 1] = s[n + n - 1 - (i << 1)] = buffer[i];
  }
  memset(result, -1, sizeof(int) * ((n + 1) >> 1));
  for (int i = 0, z = -1; i < n + n; ++i) {
    manacher[i] =
        ~z && i < end(z) ? std::min(manacher[z + z - i], end(z) - i) : 0;
    while (i - 1 - manacher[i] >= 0 && i + manacher[i] < n + n &&
           s[i - 1 - manacher[i]] == s[i + manacher[i]]) {
      manacher[i]++;
    }
    if (!~z || end(z) < end(i)) {
      z = i;
    }
  }
//   for (int i = 0; i < n + n; ++i) {
//     printf("%3d", i);
//   }
//   puts("");
//   for (int i = 0; i < n + n; ++i) {
//     printf("%3c", s[i]);
//   }
//   puts("");
//   for (int i = 0; i < n + n; ++i) {
//     printf("%3d", manacher[i]);
//   }
//   puts("");
  int head = 0, rear = 0;
  for (int i = n + 1 + (n & 1); i < n + n; i += 2) {
    if (manacher[i] && (head == rear || end(queue[rear - 1]) < end(i))) {
      queue[rear++] = i;
    }
    while (head < rear && end(queue[head]) < i + 1) {
      head++;
    }
    if (head < rear) {
      result[(n + n - i) >> 1] = (i + 1 - queue[head]);
    }
  }
  for (int i = 0; i < ((n + 1) >> 1); ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == ((n + 1) >> 1)]);
  }
}