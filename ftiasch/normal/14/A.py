# Codeforces Beta Round #14
# Problem A -- Letter
n, m = map(int, raw_input().split());
g = [];
for i in range(n):
    g.append(raw_input());
xmin, xmax, ymin, ymax = n, -1, m, -1;
for i in range(n):
    for j in range(m):
        if g[i][j] == '*':
            xmin, xmax, ymin, ymax = min(xmin, i), max(xmax, i), min(ymin, j), max(ymax, j);
for i in range(xmin, xmax + 1):
    print g[i][ymin: ymax + 1];