#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000000;
const int MAXD = 500;
const int MAXS = 5000;

int dp[1 + MAXS][MAXD];

void Initialize(int s, int d) {
    for (int i = 0; i <= s; i++)
        for (int j = 0; j < d; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
}

priority_queue<pair<int, int> > Heap;

void Dijkstra(int line, int d) {
    for (int i = 0; i < d; i++)
        if (dp[line][i] != INF)
            Heap.push(make_pair(-dp[line][i], i));
    while (!Heap.empty()) {
        int x = Heap.top().second, cost = -Heap.top().first;
        Heap.pop();
        if (cost != dp[line][x])
            continue;
        int y = (x * 10) % d;
        if (dp[line][y] > cost + 1) {
            dp[line][y] = cost + 1;
            Heap.push(make_pair(-dp[line][y], y));
        }
    }
}

void Propagate(int line, int d, int s) {
    for (int i = 0; i < d; i++)
        for (int c = 1; line + c <= s && c < 10; c++)
            dp[line + c][(i * 10 + c) % d] = min(dp[line + c][(i * 10 + c) % d], dp[line][i] + 1);
}

void Reconstitute(int s, int d) {
    if (dp[s][0] == INF) {
        printf("-1\n");
        return;
    }
    int digits = dp[s][0];
    vector<int> power10;
    power10.push_back(1 % d);
    for (int i = 1; i < digits; i++)
        power10.push_back((power10.back() * 10) % d);
    int remainder = 0;
    for (int i = digits; i >= 1; i--) {
        int start = 0;
        if (i == digits)
            start = 1;
        for (int c = start; c < 10; c++) {
            int newRemainder = ((remainder - c * power10[i - 1]) % d + d) % d;
            if (dp[s - c][newRemainder] <= i - 1) {
                s -= c;
                printf("%d", c);
                remainder = newRemainder;
                break;
            }
        }
    }
}

int main () {
    //freopen ("A.in", "r", stdin);
    //freopen ("A.out", "w", stdout);
    int d, s;
    scanf("%d%d", &d, &s);
    Initialize(s, d);
    for (int i = 0; i <= s; i++) {
        Dijkstra(i, d);
        Propagate(i, d, s);
    }
    Reconstitute(s, d);
    return 0;
}