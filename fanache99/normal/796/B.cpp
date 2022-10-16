#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;

char buffer[8192];
int pos = 8192;
char Advance() {
    if (pos == 8192) {
        fread(buffer, 1, 8192, stdin);
        pos = 0;
    }
    return buffer[pos++];
}
int Read() {
    int x = 0;
    char ch = Advance();
    while (ch < '0' || ch > '9')
        ch = Advance();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = Advance();
    }
    return x;
}

bool bad[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), k = Read();
    for (int i = 1; i <= m; i++) {
        int x = Read();
        bad[x] = true;
    }
    int where = 1;
    if (bad[1]) {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        int a = Read(), b = Read();
        if (where == a || where == b)
            where = a + b - where;
        if (bad[where]) {
            printf("%d\n", where);
            return 0;
        }
    }
    printf("%d\n", where);
    return 0;
}