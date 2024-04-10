#include <bits/stdc++.h>

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

const int MAXN = 100000;

bool seen[1 + 3 * MAXN];
vector<int> edges;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests = Read();
    for (int test = 1; test <= tests; test++) {
        int n = Read(), m = Read();
        for (int i = 1; i <= m; i++) {
            int a = Read(), b = Read();
            if (!seen[a] && !seen[b]) {
                seen[a] = seen[b] = true;
                edges.push_back(i);
            }
        }
        if (edges.size() >= n) {
            printf("Matching\n");
            for (int i = 0; i < n; i++)
                printf("%d ", edges[i]);
            printf("\n");
        }
        else {
            printf("IndSet\n");
            for (int i = 1, j = 1; i <= n; i++) {
                while (seen[j])
                    j++;
                printf("%d ", j);
                j++;
            }
            printf("\n");
        }
        edges.clear();
        for (int i = 1; i <= 3 * n; i++)
            seen[i] = false;
    }
    return 0;
}