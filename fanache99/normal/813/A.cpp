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

const int MAXN = 1000;
const int MAXVAL = 100000;

int v[1 + MAXN], s[1 + MAXVAL + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += v[i];
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read();
        s[a]++;
        s[b + 1]--;
    }
    int x = 0;
    for (int i = 1, j = 1; i <= MAXVAL; i++) {
        x += s[i];
        if (i >= sum && x) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}