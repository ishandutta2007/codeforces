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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a != 1 && b != 1) {
        printf("NO\n");
        return 0;
    }
    if (n == 1) {
        printf("YES\n0\n");
        return 0;
    }
    if (a == 1 && b == 1) {
        if (n <= 3)
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++)
                    if (i == j + 1 || j == i + 1)
                        printf("1");
                    else
                        printf("0");
                printf("\n");
            }
        }
        return 0;
    }
    printf("YES\n");
    if (a != 1)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                if ((i == j + 1 && j >= a) || (j == i + 1 && i >= a))
                    printf("1");
                else
                    printf("0");
            printf("\n");
        }
    else
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                if ((i == j + 1 && j >= b) || (j == i + 1 && i >= b) || i == j)
                    printf("0");
                else
                    printf("1");
            printf("\n");
        }
    return 0;
}