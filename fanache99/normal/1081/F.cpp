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

const int MAXN = 300;

int sum[1 + MAXN];
int changed[2], last;

int Ask(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    int answer = (x - last) & 1;
    last = x;
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    scanf("%d", &sum[n]);
    last = sum[n];
    for (int i = 1; i < n; i++) {
        int l = i - n % 2, r = i, temp = i % 2;
        if (i == 1 && n % 2 == 1) {
            l = 2;
            r = n;
            temp = 0;
        }
        int before = last;
        changed[0] = changed[1] = 0;
        while (changed[0] != 1 || changed[1] != 0)
            changed[Ask(l, r) ^ temp] ^= 1;
        int now = last;
        if (i == 1 && n % 2 == 1)
            sum[i] = sum[n] - (n - 1 - now + before) / 2;
        else
            sum[i] = (i - now + before) / 2;
        while (changed[0] || changed[1])
            changed[Ask(l, r) ^ temp] ^= 1;
    }
    printf("! ");
    for (int i = 1; i <= n; i++)
        printf("%d", sum[i] - sum[i - 1]);
    printf("\n");
    fflush(stdout);
    return 0;
}