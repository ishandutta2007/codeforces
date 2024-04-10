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

const int MAXN = 100000;
const int MAXM = 100000;

int special[1 + MAXN];
int height[1 + MAXN], dad[1 + MAXN], biggest = 1;

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

void Join(int a, int b) {
    a = FindDad(a);
    b = FindDad(b);
    if (a == b)
        return;
    if (height[a] > height[b]) {
        dad[b] = a;
        special[a] += special[b];
    }
    else {
        dad[a] = b;
        special[b] += special[a];
        if (height[a] == height[b])
            height[b]++;
    }
    biggest = max(biggest, max(special[a], special[b]));
}

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        height[i] = 1;
    }
}

struct Edge {
    int a;
    int b;
    int c;

    bool operator < (const Edge &other) const {
        return c < other.c;
    }
};

Edge edge[1 + MAXM];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), k = Read();
    for (int i = 1; i <= k; i++) {
        int x = Read();
        special[x] = 1;
    }
    Initialize(n);
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read(), c = Read();
        edge[i] = {a, b, c};
    }
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; i++) {
        Join(edge[i].a, edge[i].b);
        if (biggest == k) {
            for (int j = 1; j <= k; j++)
                printf("%d ", edge[i].c);
            return 0;
        }
    }
    return 0;
}