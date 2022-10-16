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

const int MAXN = 1000;

struct Student {
    int a;
    int b;
    int id;

    bool operator < (const Student &other) const {
        if (a != other.a)
            return a < other.a;
        return id < other.id;
    }
};

Student v[1 + MAXN];
int answer[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &v[i].a, &v[i].b);
            v[i].id = i;
        }
        sort(v + 1, v + n + 1);
        for (int i = 1, j = 1; i <= n; i++) {
            j = max(j, v[i].a);
            if (j <= v[i].b) {
                answer[v[i].id] = j;
                j++;
            }
            else
                answer[v[i].id] = 0;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", answer[i]);
        printf("\n");
    }
    return 0;
}