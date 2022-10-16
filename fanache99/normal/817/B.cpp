#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
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

const int MAXN = 100000;

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    if (v[1] != v[2] && v[2] != v[3] && v[3] != v[4]) {
        printf("1\n");
        return 0;
    }
    if (v[1] != v[2] && v[2] != v[3]) {
        int i = 3;
        while (i < n && v[i + 1] == v[3])
            i++;
        printf("%d\n", i - 3 + 1);
        return 0;
    }
    if (v[1] != v[2]) {
        int i = 2;
        while (i < n && v[i + 1] == v[2])
            i++;
        long long answer = 1LL * (i - 2) * (i - 2 + 1) / 2;
        printf("%I64d\n", answer);
        return 0;
    }
    if (v[2] != v[3]) {
        int i = 3;
        while (i < n && v[i + 1] == v[3])
            i++;
        printf("%d\n", i - 3 + 1);
        return 0;
    }
    int i = 1;
    while (i < n && v[i + 1] == v[1])
        i++;
    long long answer = 1LL * i * (i - 1) * (i - 2) / 6;
    printf("%I64d\n", answer);
    return 0;
}