#include <fstream>
#include <iostream>
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
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
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

const int MAXN = 200000;
const int SIGMA = 10;

char s[1 + MAXN];
int v[1 + MAXN], answer[1 + MAXN];
bool parity[SIGMA];

void Solve(int from, int to, int need) {
    while (to - from + 1 > need) {
        answer[from] = 9;
        from++;
    }
    for (int i = 9; i >= 0; i--)
        if (parity[i]) {
            answer[from] = i;
            from++;
        }
    for (int i = 1; i <= to; i++)
        printf("%d", answer[i]);
    printf("\n");
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d\n", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%s\n", s + 1);
        int n = strlen(s + 1);
        memset(parity, false, sizeof(parity));
        for (int i = 1; i <= n; i++) {
            v[i] = s[i] - '0';
            parity[v[i]] ^= 1;
        }
        bool found = false;
        for (int i = n; i >= 1 && !found; i--) {
            parity[v[i]] ^= 1;
            for (int j = v[i] - 1; j >= (i == 1 ? 1 : 0); j--) {
                parity[j] ^= 1;
                int total = 0;
                for (int k = 0; k < SIGMA; k++)
                    total += parity[k];
                if (total <= n - i && (n - i - total) % 2 == 0) {
                    found = true;
                    for (int p = 1; p < i; p++)
                        answer[p] = v[p];
                    answer[i] = j;
                    Solve(i + 1, n, total);
                    break;
                }
                parity[j] ^= 1;
            }
        }
        if (!found) {
            if (n % 2)
                for (int i = 1; i <= n - 1; i++)
                    printf("9");
            else
                for (int i = 1; i <= n - 2; i++)
                    printf("9");
            printf("\n");
        }
    }
    return 0;
}