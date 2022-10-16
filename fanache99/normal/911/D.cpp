//#include <iostream>
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

const int MAXN = 1500;

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int parity = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        for (int j = 1; j < i; j++)
            if (v[j] > v[i])
                parity ^= 1;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = (b - a) * (b - a + 1) / 2;
        if (x % 2)
            parity ^= 1;
        if (parity)
            printf("odd\n");
        else
            printf("even\n");
    }
    return 0;
}