#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

typedef long long ll;
const int maxn = 1000010;
int n, a[maxn], b[maxn], pos[maxn], lst[maxn];
ll pre1[maxn], pre2[maxn];
pair<int, int> p[maxn * 2];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        pre1[i] = pre1[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
        pre2[i] = pre2[i - 1] + b[i];
    }
    bool flag = 0;
    if (pre1[n] > pre2[n]) {
        swap(pre1, pre2), flag = 1;
    }
    memset(lst, -1, sizeof(lst));
    for (int i = 0, j = 0; i <= n; i++) {
        while (pre2[j + 1] <= pre1[i]) j++;
        pos[i] = j;
        if (~lst[pre1[i] - pre2[j]]) {
            int foo = lst[pre1[i] - pre2[j]];
            vector<int> V1, V2;
            for (int k = foo + 1; k <= i; k++) V1.push_back(k);
            for (int k = pos[foo] + 1; k <= j; k++) V2.push_back(k);
            if (flag) swap(V1, V2);
            printf("%d\n", V1.size());
            for (int x : V1) printf("%d ", x);
            printf("\n%d\n", V2.size());
            for (int x : V2) printf("%d ", x);
            exit(0);
        }
        lst[pre1[i] - pre2[j]] = i;
    }
    return 0;
}