#include <iostream>
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

int Read() {
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 2000;

int best[1 + MAXN][1 + MAXN];

struct Thing {
    int a;
    int b;
    int c;

    bool operator < (const Thing &other) const {
        return c < other.c;
    }
};

vector<Thing> v;
vector<int> here[1 + MAXN];

int dad[1 + MAXN];

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        here[i].push_back(i);
    }
}

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

void Join(int a, int b, int c) {
    int roota = FindDad(a), rootb = FindDad(b);
    for (auto &it : here[roota])
        for (auto &jt : here[rootb])
            if (best[it][a] + best[jt][b] + c != best[it][jt]) {
                printf("NO\n");
                exit(0);
            }
    dad[rootb] = roota;
    for (auto &it : here[rootb])
        here[roota].push_back(it);
    here[rootb].clear();
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            best[i][j] = Read();
    for (int i = 1; i <= n; i++)
        if (best[i][i]) {
            printf("NO\n");
            return 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (best[i][j] != best[j][i] || !best[i][j]) {
                printf("NO\n");
                return 0;
            }
            v.push_back({i, j, best[i][j]});
        }
    sort(v.begin(), v.end());
    Initialize(n);
    for (auto &it : v) {
        int a = it.a, b = it.b, c = it.c;
        if (FindDad(a) == FindDad(b))
            continue;
        Join(a, b, c);
    }
    printf("YES\n");
    return 0;
}