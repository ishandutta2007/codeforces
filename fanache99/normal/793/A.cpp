#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;
const int INF = 1000000000;
const int MAXN = 100000;

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

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    int first = k, big = -INF, small = INF;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        big = max(big, x);
        small = min(small, x);
        if (first == k)
            first = x % k;
        else
            if (first != x % k) {
                printf("-1\n");
                return 0;
            }
        v[i] = x;
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        answer += (v[i] - small) / k;
    printf("%I64d\n", answer);
    return  0;
}