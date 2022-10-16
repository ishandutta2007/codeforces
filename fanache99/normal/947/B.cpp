#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100000;

long long v[1 + MAXN], t[1 + MAXN];
priority_queue<long long, vector<long long>, greater<long long> > Heap;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    long long lazy = 0;
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &t[i]);
    for (int i = 1; i <= n; i++) {
        Heap.push(v[i] + lazy);
        lazy += t[i];
        long long answer = 0;
        while (!Heap.empty() && Heap.top() <= lazy) {
            answer += t[i] - (lazy - Heap.top());
            Heap.pop();
        }
        answer += 1LL * t[i] * Heap.size();
        printf("%I64d ", answer);
    }
    return 0;
}