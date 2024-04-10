#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
//#include "cup.h"

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

const int MAXN = 50;
const int MAXVAL = 100000;

int a[1 + MAXN][1 + MAXN];
bool seen[1 + MAXVAL];

bool Check(int n, int l, int c) {
    for (int i = 1; i <= n; i++)
        seen[a[l][i]] = true;
    bool found = false;
    for (int i = 1; i <= n && !found; i++)
        if (a[i][c] < a[l][c] && seen[a[l][c] - a[i][c]])
            found = true;
    for (int i = 1; i <= n; i++)
        seen[a[l][i]] = false;
    return found;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 1 && !Check(n, i, j)) {
                printf("No\n");
                return 0;
            }
    printf("Yes\n");
    return 0;
}