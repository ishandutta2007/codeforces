#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 300000;

vector<int> g[1 + MAXN];

struct Person {
    int x;
    int y;
    int id;

    bool operator < (const Person &other) const {
        return x - y <= other.x - other.y;
    }
};

Person v[1 + MAXN], w[1 + MAXN];
long long xSum[1 + MAXN], ySum[1 + MAXN], answer[1 + MAXN];

int TeamUp(int a, int b) {
    return min(v[a].x + v[b].y, v[a].y + v[b].x);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v[i].x, &v[i].y);
        v[i].id = i;
        w[i] = v[i];
        g[i].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sort(w + 1, w + n + 1);
    for (int i = 1; i <= n; i++) {
        xSum[i] = xSum[i - 1] + w[i].x;
        ySum[i] = ySum[i - 1] + w[i].y;
    }
    for (int i = 1, j = 1; i <= n; i++) {
        long long sum = 1LL * i * w[i].y + xSum[i] + (ySum[n] - ySum[i]) + 1LL * (n - i) * w[i].x;
        for (auto &it : g[w[i].id])
            sum -= TeamUp(w[i].id, it);
        answer[w[i].id] = sum;
    }
    for (int i = 1; i <= n; i++)
        printf("%I64d ", answer[i]);
    return 0;
}