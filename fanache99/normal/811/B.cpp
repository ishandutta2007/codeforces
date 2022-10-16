#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

const int MAXN = 10000;

int p[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    for (int i = 1; i <= n; i++)
        p[i] = Read();
    for (int i = 1; i <= m; i++) {
        int l = Read(), r = Read(), x = Read();
        if (x < l || x > r) {
            printf("Yes\n");
            continue;
        }
        int smaller = 0;
        for (int j = l; j <= r; j++)
            if (p[j] <= p[x])
                smaller++;
        if (smaller == x - l + 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}