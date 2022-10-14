#include <bits/stdc++.h>

const int N = 100000;
const int M = 3000;

int n, x[N][2], y[N][2], hrz[M + 1][M + 1], vtc[M + 1][M + 1],
    area[M + 1][M + 1];

bool is_hrz(int y, int x1, int x2) { return hrz[x2][y] == hrz[x1][y]; }

bool is_vtc(int x, int y1, int y2) { return vtc[x][y2] == vtc[x][y1]; }

int all(int x1, int y1, int x2, int y2) {
  return area[x2][y2] - area[x1][y2] - area[x2][y1] + area[x1][y1];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      scanf("%d%d", &x[i][j], &y[i][j]);
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int j = y[k][0] + 1; j < y[k][1]; ++j) {
      for (int i = x[k][0] + 1; i <= x[k][1]; ++i) {
        hrz[i][j] = 1;
      }
    }
    for (int i = x[k][0] + 1; i < x[k][1]; ++i) {
      for (int j = y[k][0] + 1; j <= y[k][1]; ++j) {
        vtc[i][j] = 1;
      }
    }
    for (int i = x[k][0] + 1; i <= x[k][1]; ++i) {
      for (int j = y[k][0] + 1; j <= y[k][1]; ++j) {
        area[i][j] = 1;
      }
    }
  }
  for (int j = 1; j <= M; ++j) {
    for (int i = 1; i <= M; ++i) {
      hrz[i][j] += hrz[i - 1][j];
    }
  }
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= M; ++j) {
      vtc[i][j] += vtc[i][j - 1];
    }
  }
  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= M; ++j) {
      area[i][j] += area[i - 1][j] + area[i][j - 1] - area[i - 1][j - 1];
    }
  }
  for (int k = 0; k < n; ++k) {
    int x1 = x[k][0];
    int y1 = y[k][0];
    for (int length = 1;
         x1 + length <= M && y1 + length <= M &&
         all(x1, y1, x1 + length, y1 + length) == length * length;
         ++length) {
      if (is_hrz(y1, x1, x1 + length) && is_hrz(y1 + length, x1, x1 + length) &&
          is_vtc(x1, y1, y1 + length) && is_vtc(x1 + length, y1, y1 + length)) {
        std::vector<int> answer;
        for (int i = 0; i < n; ++i) {
          if (x1 <= x[i][0] && y1 <= y[i][0] && x[i][1] <= x1 + length &&
              y[i][1] <= y1 + length) {
            answer.push_back(i);
          }
        }
        printf("YES %d\n", (int)answer.size());
        for (int i = 0; i < (int)answer.size(); ++i) {
          printf("%d%c", answer[i] + 1,
                 i == (int)answer.size() - 1 ? '\n' : ' ');
        }
        return 0;
      }
    }
  }
  puts("NO");
}