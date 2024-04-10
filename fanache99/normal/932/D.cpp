#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

long long Read() {
    long long answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

char ReadCh() {
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 400000;
const int MAXLOG = 18;

int weight[1 + MAXN], depth[1 + MAXN];
int dad[1 + MAXLOG][1 + MAXN], go[1 + MAXLOG][1 + MAXN], biggest[1 + MAXLOG][1 + MAXN];
long long sum[1 + MAXLOG][1 + MAXN];

int Search(int node) {
    int limit = weight[node];
    node = dad[0][node];
    for (int step = MAXLOG; step >= 0; step--)
        if (biggest[step][node] < limit)
            node = dad[step][node];
    return node;
}

void Add(int x, int y, int &n) {
    n++;
    weight[n] = y;
    dad[0][n] = x;
    biggest[0][n] = weight[n];
    go[0][n] = Search(n);
    depth[n] = depth[go[0][n]] + 1;
    sum[0][n] = weight[n];
    for (int i = 1; i <= MAXLOG; i++) {
        dad[i][n] = dad[i - 1][dad[i - 1][n]];
        biggest[i][n] = max(biggest[i - 1][n], biggest[i - 1][dad[i - 1][n]]);
        go[i][n] = go[i - 1][go[i - 1][n]];
        sum[i][n] = sum[i - 1][n] + sum[i - 1][go[i - 1][n]];
    }
}

int Query(int node, long long limit) {
    int answer = 0;
    for (int step = MAXLOG; step >= 0; step--)
        if ((1 << step) <= depth[node] && sum[step][node] <= limit) {
            limit -= sum[step][node];
            answer += (1 << step);
            node = go[step][node];
        }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int q = Read(), last = 0, n = 1;
    depth[1] = 1;
    for (int i = 1; i <= q; i++) {
        int type = Read();
        long long x = Read() ^ last, y = Read() ^ last;
        if (type == 1)
            Add(x, y, n);
        else {
            last = Query(x, y);
            printf("%d\n", last);
        }
    }
    return 0;
}