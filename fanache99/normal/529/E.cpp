#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>
#include <map>

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

const int MAXN = 5000;

int v[1 + MAXN];
map<int, int> seen;

void Precompute(int n, int k) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (seen[v[i] * j] == 0 || seen[v[i] * j] > j)
                seen[v[i] * j] = j;
}

int Solve(int x, int n, int k) {
    int answer = 2 * k;
    if (seen[x] != 0)
        answer = seen[x];
    for (auto &it : seen) {
        if (it.first >= x)
            break;
        if (it.second == 0)
            continue;
        int need = x - it.first;
        if (seen[need] != 0)
            answer = min(answer, it.second + seen[need]);
    }
    if (answer > k)
        answer = -1;
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    Precompute(n, k);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", Solve(x, n, k));
    }
    return 0;
}