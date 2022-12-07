#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000000];
queue<int> q;
int dist[1000000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v > 0 && dist[v - 1] == -1) {
            dist[v - 1] = dist[v] + 1;
            q.push(v - 1);
        }
        if (v < n - 1 && dist[v + 1] == -1) {
            dist[v + 1] = dist[v] + 1;
            q.push(v + 1);
        }
        if (dist[a[v]] == -1) {
            dist[a[v]] = dist[v] + 1;
            q.push(a[v]);
        }
    }
    REP(i, n) printf("%d ", dist[i]);
    printf("\n");
    return 0;
}