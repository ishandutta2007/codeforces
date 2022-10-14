#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((int)(v).size())

const int N = 100000;
const int LOG = 19;

int n, m, x[N][2], y[N][2], z[N], a[N], b[N], answer[N], order[N];
std::vector <int> values;

bool by_z(int i, int j) {
    return z[i] < z[j];
}

int root[N << 1];

int getID(int l, int r) {
    return l + r | l != r;
}

std::pair <int, int> key[N * LOG];
int treapCount, weight[N * LOG], minY[N * LOG], maxY[N * LOG], minID[N * LOG], children[N * LOG][2];

void update(int &x) {
    minY[x] = children[x][0] ? minY[children[x][0]] : key[x].first;
    maxY[x] = children[x][1] ? maxY[children[x][1]] : key[x].first;
    minID[x] = std::min(key[x].second, std::min(minID[children[x][0]], minID[children[x][1]]));
}

void rotate(int &x, int t) {
    int y = children[x][t];
    children[x][t] = children[y][1 ^ t];
    children[y][1 ^ t] = x;
    update(x);
    update(y);
    x = y;
}

void treapInsert(int &x, const std::pair <int, int> &k) {
    if (x)  {
        int t = key[x] < k;
        treapInsert(children[x][t], k);
        if (weight[children[x][t]] < weight[x]) {
            rotate(x, t);
        }
    } else {
        x = treapCount ++;
        key[x] = k;
        weight[x] = rand() << 15 | rand();
    }
    update(x);
}

void treapDelete(int &x, const std::pair <int, int> &k) {
    if (key[x] != k) {
        treapDelete(children[x][key[x] < k], k);
    } else {
        if (children[x][0] || children[x][1]) {
            rotate(x, weight[children[x][0]] > weight[children[x][1]]);
            treapDelete(x, k);
        } else {
            x = 0;
            return;
        }
    }
    update(x);
}

int treapQuery(int &x, int y1, int y2) {
    if (!x || y2 < minY[x] || maxY[x] < y1) {
        return INT_MAX;
    }
    if (y1 <= minY[x] && maxY[x] <= y2) {
        return minID[x];
    }
    int ret = std::min(treapQuery(children[x][0], y1, y2), treapQuery(children[x][1], y1, y2));
    if (y1 <= key[x].first && key[x].first <= y2) {
        ret = std::min(ret, key[x].second);
    }
    return ret;
}

void segmentTreeInsert(int l, int r, int x, int y, int w) {
    if (x < values[l] || values[r] < x) {
        return;
    }
    treapInsert(root[getID(l, r)], std::make_pair(y, w));
    if (l < r) {
        int m = l + r >> 1;
        segmentTreeInsert(l, m, x, y, w);
        segmentTreeInsert(m + 1, r, x, y, w);
    }
}

void segmentTreeDelete(int l, int r, int x, int y, int w) {
    if (x < values[l] || values[r] < x) {
        return;
    }
    treapDelete(root[getID(l, r)], std::make_pair(y, w));
    if (l < r) {
        int m = l + r >> 1;
        segmentTreeDelete(l, m, x, y, w);
        segmentTreeDelete(m + 1, r, x, y, w);
    }
}

int segmentTreeQuery(int l, int r, int x1, int x2, int y1, int y2) {
    if (x2 < values[l] || values[r] < x1) {
        return INT_MAX;
    }
    if (x1 <= values[l] && values[r] <= x2) {
        return treapQuery(root[getID(l, r)], y1, y2);
    }
    int m = l + r >> 1;
    return std::min(segmentTreeQuery(l, m, x1, x2, y1, y2), segmentTreeQuery(m + 1, r, x1, x2, y1, y2));
}

int main() {
    treapCount = 1;
    weight[0] = minY[0] = minID[0] = INT_MAX;
    maxY[0] = INT_MIN;
    memset(children, 0, sizeof(children));
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d%d%d", &x[i][0], &x[i][1], &y[i][0], &y[i][1], z + i);
        order[i] = i;
    }
    std::sort(order, order + n, by_z);
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", a + i, b + i);
        values.push_back(a[i]);
    }
    std::sort(ALL(values));
    values.erase(std::unique(ALL(values)), values.end());
    memset(answer, -1, sizeof(answer));
    memset(root, 0, sizeof(root));
    for (int i = 0; i < m; ++ i) {
        segmentTreeInsert(0, SIZE(values) - 1, a[i], b[i], i);
    }
    for (int _ = 0; _ < n; ++ _) {
        int i = order[_];
        int ret = segmentTreeQuery(0, SIZE(values) - 1, x[i][0], x[i][1], y[i][0], y[i][1]);
        if (ret != INT_MAX) {
            answer[ret] = i;
            segmentTreeDelete(0, SIZE(values) - 1, a[ret], b[ret], ret);
        }
    }
    for (int i = 0; i < m; ++ i) {
        printf("%d\n", answer[i] + 1);
    }
    return 0;
}