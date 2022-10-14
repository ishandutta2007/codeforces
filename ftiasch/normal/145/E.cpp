// Codeforces Round #104
// Problem E -- Lucky Queries
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1111111;

int n, m, data[N << 2][2][2];
bool cover[N << 2];
char init[N];

template <class T> 
T max3(T a, T b, T c) {
    return max(a, max(b, c));
}

void update(int t) {
    data[t][0][0] = data[t + t][0][0] + data[t + t + 1][0][0];
    data[t][0][1] = max3(data[t + t][0][0] + data[t + t + 1][1][1],
            data[t + t][0][0] + data[t + t + 1][0][1],
            data[t + t][0][1] + data[t + t + 1][1][1]);
    data[t][1][0] = max3(data[t + t][1][1] + data[t + t + 1][0][0],
            data[t + t][1][1] + data[t + t + 1][1][0],
            data[t + t][1][0] + data[t + t + 1][0][0]);
    data[t][1][1] = data[t + t][1][1] + data[t + t + 1][1][1];
}

void build(int t, int l, int r) {
    if (l == r) {
        int c = init[l] == '7';
        data[t][c][c] = 1;
    } else {
        int m = (l + r) >> 1;
        build(t + t, l, m);
        build(t + t + 1, m + 1, r);
        update(t);
    }
}

void access(int t) {
    cover[t] ^= 1;
    swap(data[t][0][0], data[t][1][1]);
    swap(data[t][0][1], data[t][1][0]);
}

void reverse(int t, int l, int r, int a, int b) {
    if (b < l || r < a) {
        return;
    }
    if (a <= l && r <= b) {
        access(t);
    } else {
        int m = (l + r) >> 1;
        if (cover[t]) {
            cover[t] = false;
            access(t + t);
            access(t + t + 1);
        }
        reverse(t + t, l, m, a, b);
        reverse(t + t + 1, m + 1, r, a, b);
        update(t);
    }
}

int main() {
    scanf("%d%d%s", &n, &m, init + 1);
    memset(cover, 0, sizeof(cover));
    memset(data, 0, sizeof(data));
    build(1, 1, n);
    while (m --) {
        char buffer[11];
        scanf("%s", buffer);
        if (*buffer == 'c') {
            printf("%d\n", max3(data[1][0][0], data[1][0][1], data[1][1][1]));
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            reverse(1, 1, n, a, b);
        }
    }
    return 0;
}