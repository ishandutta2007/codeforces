#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100010;
const long long INF = 1000000000000000000LL;

vector<pair<int, int> > g[MAXN];
long long best[MAXN];
bool special[MAXN], inQueue[MAXN];
queue<int> Queue;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (k == 0) {
        printf("-1");
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++)
        best[i] = INF;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d" ,&x);
        best[x] = 0;
        special[x] = inQueue[x] = true;
        Queue.push(x);
    }
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        inQueue[node] = false;
        for (auto &nextNode : g[node])
            if (best[nextNode.first] > best[node] + nextNode.second) {
                best[nextNode.first] = best[node] + nextNode.second;
                if (!inQueue[nextNode.first]) {
                    inQueue[nextNode.first] = true;
                    Queue.push(nextNode.first);
                }
            }
    }
    long long answer = INF;
    for (int i = 1; i <= n; i++)
        if (!special[i])
            answer = min(answer, best[i]);
    if (answer == INF)
        answer = -1;
    printf("%I64d", answer);
    return 0;
}