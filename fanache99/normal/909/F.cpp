//#inlude <iostream>
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
#include <cstring>

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

const int MAXN = 100000;

int answer[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int initial = n;
    if (n % 2)
        printf("NO\n");
    else {
        printf("YES\n");
        while (n) {
            int k = 0;
            while ((1 << k) <= n)
                k++;
            k--;
            int a = (1 << k) - 1, b = (1 << k);
            while (b <= n) {
                answer[a] = b;
                answer[b] = a;
                a--;
                b++;
            }
            n = a;
        }
        n = initial;
        for (int i = 1; i <= n; i++)
            printf("%d ", answer[i]);
        printf("\n");
    }
    if (n <= 5 || n == (n & -n))
        printf("NO\n");
    else {
        printf("YES\n");
        if (n == 6)
            printf("3 6 2 5 1 4");
        else {
            printf("7 3 6 5 1 2 4");
            int a = 8;
            while (a <= n) {
                int b = min(n, 2 * a - 1);
                for (int i = a; i < b; i++)
                    printf(" %d", i + 1);
                printf(" %d", a);
                a = b + 1;
            }
        }
    }
    return 0;
}