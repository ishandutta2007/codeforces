#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

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

const int MAXN = 100;

int a[1 + MAXN][1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > n * n) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int subtract = 1;
            if (i != j)
                subtract++;
            if (k >= subtract) {
                k -= subtract;
                a[i][j] = a[j][i] = 1;
            }
        }
    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
    return 0;
}