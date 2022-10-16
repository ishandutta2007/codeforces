#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 20000010;
const long long INFLL = 1000000000000000000LL;

long long best[MAXN];
bool inQueue[MAXN];

class Compare {
    public:
        bool operator()(const int &a, const int &b) {
            return best[a] > best[b];
        }
};

priority_queue<int, vector<int>, Compare> Heap;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    long long x, y;
    scanf("%d%I64d%I64d", &n, &x, &y);
    best[0] = 0;
    Heap.push(0);
    for (int i = 1; i <= n + 10; i++)
        best[i] = INFLL;
    while (!Heap.empty()) {
        int node = Heap.top();
        Heap.pop();
        if (node >= n + 10)
            continue;
        if (node - 1 >= 0 && best[node - 1] > best[node] + x) {
            best[node - 1] = best[node] + x;
            Heap.push(node - 1);
        }
        if (node + 1 <= n + 10 && best[node + 1] > best[node] + x) {
            best[node + 1] = best[node] + x;
            Heap.push(node + 1);
        }
        if (2 * node <= n + 10 && best[2 * node] > best[node] + y) {
            best[2 * node] = best[node] + y;
            Heap.push(2 * node);
        }
    }
    printf("%I64d", best[n]);
    return 0;
}