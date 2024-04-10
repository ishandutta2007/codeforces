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

const int MAXN = 1000;

int seen[1 + MAXN], answer[1 + MAXN];
vector<int> g[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b != n) {
            printf("NO\n");
            return 0;
        }
        seen[a]++;
        answer[a] = a;
    }
    for (int i = n; i >= 1; i--) {
        while (seen[i] > 1) {
            int j = i - 1;
            while (j >= 1 && answer[j])
                j--;
            if (j < 1) {
                printf("NO\n");
                return 0;
            }
            answer[j] = i;
            g[i].push_back(j);
            seen[i]--;
        }
        if (seen[i]) {
            answer[i] = i;
            g[i].push_back(i);
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        if (!g[i].empty()) {
            reverse(g[i].begin(), g[i].end());
            g[i].push_back(n);
            for (int j = 0; j < g[i].size() - 1; j++)
                printf("%d %d\n", g[i][j], g[i][j + 1]);
        }
    return 0;
}