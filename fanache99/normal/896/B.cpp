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
const int INF = 1000000;

int v[1 + MAXN + 1];

bool Ok(int n) {
    for (int i = 1; i <= n; i++)
        if (v[i] == 0 || v[i] > v[i + 1])
            return false;
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, c, a = 1, b;
    scanf("%d%d%d", &n, &m, &c);
    b = n;
    v[n + 1] = INF;
    while (!Ok(n)) {
        int x;
        scanf("%d", &x);
        if (a <= b)
            if (x <= c / 2)
                if (x >= v[a - 1]) {
                    printf("%d\n", a);
                    fflush(stdout);
                    v[a] = x;
                    a++;
                }
                else {
                    int i = a - 1;
                    while (x < v[i - 1])
                        i--;
                    printf("%d\n", i);
                    fflush(stdout);
                    v[i] = x;
                }
            else
                if (x <= v[b + 1]) {
                    printf("%d\n", b);
                    fflush(stdout);
                    v[b] = x;
                    b--;
                }
                else {
                    int i = b + 1;
                    while (x > v[i + 1])
                        i++;
                    printf("%d\n", i);
                    fflush(stdout);
                    v[i] = x;
                }
        else
            if (x <= v[a - 1]) {
                int i = a - 1;
                while (x < v[i - 1])
                    i--;
                printf("%d\n", i);
                fflush(stdout);
                v[i] = x;
            }
            else {
                int i = b + 1;
                while (x > v[i + 1])
                    i++;
                printf("%d\n", i);
                fflush(stdout);
                v[i] = x;
            }
    }
    return 0;
}