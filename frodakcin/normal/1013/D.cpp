#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 202000;
const int MAXM = 202000;
const int MAXQ = 202000;

int N, M, Q;

int p[MAXN + MAXM];
int r[MAXN + MAXM];
bool v[MAXN + MAXM];
int ans;
void init() {
    for(int i = 0;i < M + N;i++) {
        p[i] = i;
        r[i] = 1;
    }
}
int find(int r) {
    if(p[r] == r) return r;
    return p[r] = find(p[r]);
}
void merge(int a, int b) {
    if(find(a) == find(b)) return;
    if(r[find(a)] < r[find(b)]) return merge(b, a);
    r[find(a)] += r[find(b)];
    r[find(b)] = 0;
    p[find(b)] = find(a);
    ans++;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    init();
    ans = 0;
    for(int i = 0;i < Q;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, N + b);
    }
    printf("%d\n", (N + M - 1) - ans);
}