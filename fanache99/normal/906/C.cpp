//#include <iostream>
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

const int MAXN = 22;

int n, answer;
vector<int> nodes;
bool used[MAXN];
int mask[MAXN];

bool Check() {
    for (int i = 0; i < n; i++)
        if (mask[i] != (1 << n) - 1)
            return false;
    nodes.clear();
    for (int i = 0; i < n; i++)
        if (used[i])
            nodes.push_back(i);
    answer = nodes.size();
    return true;
}

void Backtracking(int node, int pressed) {
    if (pressed >= answer)
        return;
    if (Check() || node == n)
        return;
    used[node] = true;
    int before[MAXN];
    for (int i = 0; i < n; i++)
        before[i] = mask[i];
    for (int i = 0; i < n; i++)
        if (i != node && mask[node] & (1 << i))
            mask[i] |= mask[node];
    Backtracking(node + 1, pressed + 1);
    used[node] = false;
    for (int i = 0; i < n; i++)
        mask[i] = before[i];
    Backtracking(node + 1, pressed);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int m;
    scanf("%d%d", &n, &m);
    answer = n + 1;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        mask[a] |= 1 << b;
        mask[b] |= 1 << a;
    }
    for (int i = 0; i < n; i++)
        mask[i] |= 1 << i;
    Backtracking(0, 0);
    printf("%d\n", answer);
    for (auto &it : nodes)
        printf("%d ", it + 1);
    return 0;
}