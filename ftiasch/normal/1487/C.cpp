#include <bits/stdc++.h>

const int N = 100;

int graph[N][N];

void win(int a, int b) {
  graph[a][b] = 1;
  graph[b][a] = -1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    memset(graph, 0, sizeof(graph));
    if (n & 1) {
      int half = n >> 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= half; ++j) {
          win(i, (i + j) % n);
        }
      }
    } else {
      int half = (n >> 1) - 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= half; ++j) {
          win(i, (i + j) % n);
        }
      }
    }
    // for (int i = 0; i < n; ++i) {
    //   int score = 0;
    //   for (int j = 0; j < n; ++j) {
    //     if (i != j) {
    //       if (graph[i][j] == 0) {
    //         score++;
    //       } else if (graph[i][j] == 1) {
    //         score += 3;
    //       }
    //     }
    //   }
    //   printf("n=%d %d %d\n", n, i, score);
    // }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        printf("%d ", graph[i][j]);
      }
    }
    puts("");
  }
}