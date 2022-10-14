// Codeforces Round #107
// Problem B -- Quantity of Strings
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1111;
const int MOD = 1000000007;

int parent[N];

int powMod(int a, int n, int m) {
    int result = 1 % m;
    while (n) {
        if (n & 1) {
            result = ((long long)result * a) % m;
        }
        a = ((long long)a * a) % m;
        n >>= 1;
    }
    return result;
}

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

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i) {
        parent[i] = i;
    }
    for (int i = 0; i + k <= n; ++ i) {
        for (int j = 0; j < k; ++ j) {
            merge(i + j, i + k - 1 - j);
        }
    }
    int basicCount = 0;
    for (int i = 0; i < n; ++ i) {
        if (parent[i] == i) {
            basicCount ++;
        }
    }
    printf("%d\n", powMod(m, basicCount, MOD));
    return 0;
}