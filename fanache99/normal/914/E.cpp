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

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int SIGMA = 20;
const int MAXN = 200000;
const int MAXVAL = 1 << 20;

vector<int> g[1 + MAXN];
char letter[1 + MAXN];
long long answer[1 + MAXN], add[1 + MAXN];
int seen[MAXVAL], weight[1 + MAXN], nodes[1 + MAXN];
bool out[1 + MAXN];

void GetWeight(int node, int father) {
    weight[node] = 1;
    nodes[0]++;
    nodes[nodes[0]] = node;
    for (auto &son : g[node])
        if (son != father && !out[son]) {
            GetWeight(son, node);
            weight[node] += weight[son];
        }
}

void Change(int node, int father, int sign, int mask) {
    mask ^= (1 << (letter[node] - 'a'));
    seen[mask] += sign;
    for (auto &son : g[node])
        if (son != father && !out[son])
            Change(son, node, sign, mask);
}

void Add(int node, int father, int centroid, int mask) {
    mask ^= 1 << (letter[node] - 'a');
    add[node] = 0;
    add[node] += seen[mask];
    for (int i = 0; i < SIGMA; i++)
        add[node] += seen[mask ^ (1 << i)];
    add[centroid] += add[node];
    for (auto &son : g[node])
        if (son != father && !out[son]) {
            Add(son, node, centroid, mask);
            add[node] += add[son];
        }
    answer[node] += add[node];
}

void Solve(int node) {
    nodes[0] = 0;
    GetWeight(node, 0);
    if (nodes[0] == 1) {
        answer[node]++;
        return;
    }
    int centroid;
    for (int i = 1; i <= nodes[0]; i++) {
        bool ok = true;
        node = nodes[i];
        if (nodes[0] - weight[node] > nodes[0] / 2)
            continue;
        for (auto &son : g[node])
            if (weight[son] < weight[node] && weight[son] > nodes[0] / 2) {
                ok = false;
                break;
            }
        if (!ok)
            continue;
        centroid = node;
        break;
    }
    seen[0]++;
    for (auto &son : g[centroid])
        if (!out[son])
            Change(son, centroid, 1, 0);
    add[centroid] = 0;
    add[centroid] += seen[1 << (letter[node] - 'a')];
    for (int i = 0; i < SIGMA; i++)
        add[centroid] += seen[(1 << (letter[centroid] - 'a')) ^ (1 << i)];
    for (auto &son : g[centroid])
        if (!out[son]) {
            Change(son, centroid, -1, 0);
            Add(son, centroid, centroid, 1 << (letter[centroid] - 'a'));
            Change(son, centroid, 1, 0);
        }
    for (auto &son : g[centroid])
        if (!out[son])
            Change(son, centroid, -1, 0);
    seen[0]--;
    answer[centroid] += 1 + add[centroid] / 2;
    out[centroid] = true;
    for (auto &son : g[centroid])
        if (!out[son])
            Solve(son);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i < n; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        letter[i] = ReadCh();
    Solve(1);
    for (int i = 1; i <= n; i++)
        printf("%I64d ", answer[i]);
    return 0;
}