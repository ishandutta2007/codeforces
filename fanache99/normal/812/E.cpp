#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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
const int MAXVAL = 10000000;

vector<int> g[1 + MAXN];
int value[1 + MAXN], good[1 + MAXVAL], bad[1 + MAXVAL], xorSum = 0, goodTotal = 0, badTotal = 0;
bool relevant[1 + MAXN];

void DFS(int node, int father) {
    if (g[node].size() == 1 && node != 1) {
        relevant[node] = true;
        xorSum ^= value[node];
        good[value[node]]++;
        goodTotal++;
        return;
    }
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            relevant[node] = relevant[son] ^ 1;
        }
    if (relevant[node]) {
        xorSum ^= value[node];
        good[value[node]]++;
        goodTotal++;
    }
    else {
        bad[value[node]]++;
        badTotal++;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        value[i] = Read();
    for (int i = 2; i <= n; i++) {
        int x = Read();
        g[x].push_back(i);
        g[i].push_back(x);
    }
    DFS(1, 0);
    long long answer = 0;
    if (!xorSum) {
        answer = 1LL * goodTotal * (goodTotal - 1) / 2 + 1LL * badTotal * (badTotal - 1) / 2;
        for (int i = 1; i <= MAXVAL; i++)
            answer += 1LL * bad[i] * good[i];
    }
    else
        for (int i = 1; i <= MAXVAL; i++)
            if ((xorSum ^ i) <= MAXVAL)
                answer += 1LL * good[i] * bad[xorSum ^ i];
    printf("%I64d\n", answer);
    return 0;
}