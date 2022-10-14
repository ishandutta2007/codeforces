#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1111111;
const int INF = 1000000000;

int n, parent[N];
char str[N];

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void merge(int i, int j) {
    if (find(i) != find(j)) {
        parent[find(i)] = find(j);
    }
}

bool isSingle(int i) {
    if (0 <= i && i < n && str[i] == '1') {
        if (i - 1 >= 0 && str[i - 1] == '1') {
            return false;
        }
        if (i + 1 < n && str[i + 1] == '1') {
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; ++ i) {
        parent[i] = i;
    }
    for (int i = 1; i < n; ++ i) {
        if (str[i - 1] == '1' && str[i] == '1') {
            merge(i - 1, i);
        }
    }
    for (int i = 1; i + 1 < n; ++ i) {
        if (str[i] == '0' && str[i - 1] == '1' && str[i + 1] == '1'
                && !isSingle(i - 1) && !isSingle(i + 1)) {
            merge(i - 1, i);
            merge(i, i + 1);
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (isSingle(i)) {
            int j = i;
            while (isSingle(j + 2)) {
                j += 2;
            }
            if (0 <= i - 2 && str[i - 2] == '1'
                    && j + 2 < n && str[j + 2] == '1') {
                for (int k = i - 2; k < j + 2; ++ k) {
                    merge(k, k + 1);
                }
            }
            i = j;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i = find(i) + 1) {
        if (str[i] == '0') {
            continue;
        }
        if (parent[i] == i) {
            ret ++;
        } else {
            int j = find(i);
            ret ++;
            ret ++;
            for (int k = i; k <= j; ++ k) {
                if (str[k] == '0') {
                    ret ++;
                }
            }
        }
    }
    printf("%d\n", ret);
    // copy
    for (int i = 0; i < n; i = find(i) + 1) {
        if (str[i] == '0') {
            continue;
        }
        if (parent[i] == i) {
            printf("+2^%d\n", n - i - 1);
        } else {
            int j = find(i);
            printf("+2^%d\n", n - i);
            printf("-2^%d\n", n - j - 1);
            for (int k = i; k <= j; ++ k) {
                if (str[k] == '0') {
                    printf("-2^%d\n", n - 1 - k);
                }
            }
        }
    }
    return 0;
}