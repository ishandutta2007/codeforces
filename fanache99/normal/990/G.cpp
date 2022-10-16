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

const int MAXN = 200000;
const int MAXD = 6;

vector<int> g[1 + MAXN];
vector<int> divisible[1 + MAXN];
int v[1 + MAXN], low[1 + MAXN];
int number[1 + MAXD], power[1 + MAXD], primes, id;

void Sieve(int n) {
    for (int i = 2; i <= n; i++)
        if (!low[i]) {
            low[i] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    if (!low[j])
                        low[j] = i;
        }
}

void Backtracking(int level, int value) {
    if (level == primes + 1) {
        divisible[value].push_back(id);
        return;
    }
    Backtracking(level + 1, value);
    for (int i = 1; i <= power[level]; i++) {
        value *= number[level];
        Backtracking(level + 1, value);
    }
}

void GetDivisors(int node, int value) {
    primes = 0;
    while (value != 1) {
        primes++;
        number[primes] = low[value];
        power[primes] = 0;
        while (low[value] == number[primes]) {
            power[primes]++;
            value /= low[value];
        }
    }
    id = node;
    Backtracking(1, 1);
}

long long answer[1 + MAXN];
int dad[1 + MAXN], weight[1 + MAXN];
bool active[1 + MAXN];

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

void Join(int a, int b, int c) {
    a = FindDad(a);
    b = FindDad(b);
    answer[c] += 1LL * weight[a] * weight[b];
    if (rand() % 2) {
        dad[a] = b;
        weight[b] += weight[a];
    }
    else {
        dad[b] = a;
        weight[a] += weight[b];
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    Sieve(MAXN);
    int n = Read();
    for (int i = 1; i <= n; i++) {
        v[i] = Read();
        GetDivisors(i, v[i]);
        dad[i] = i;
        weight[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    srand(time(0));
    for (int i = 1; i <= MAXN; i++) {
        for (auto &node : divisible[i]) {
            active[node] = true;
            answer[i]++;
            for (auto &it : g[node])
                if (active[it])
                    Join(node, it, i);
        }
        for (auto &node : divisible[i]) {
            dad[node] = node;
            weight[node] = 1;
            active[node] = false;
        }
    }
    for (int i = MAXN; i >= 1; i--)
        for (int j = 2 * i; j <= MAXN; j += i)
            answer[i] -= answer[j];
    for (int i = 1; i <= MAXN; i++)
        if (answer[i])
            printf("%d %I64d\n", i, answer[i]);
    return 0;
}