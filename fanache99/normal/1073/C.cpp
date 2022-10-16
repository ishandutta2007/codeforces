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

const int MAXN = 200000;

char s[1 + MAXN];
int dx[255], dy[255];
int xSum[1 + MAXN], ySum[1 + MAXN];

bool Check(int n, int l, int x, int y) {
    for (int i = 1; i + l - 1 <= n; i++) {
        int xNow = xSum[i - 1] + (xSum[n] - xSum[i + l - 1]);
        int yNow = ySum[i - 1] + (ySum[n] - ySum[i + l - 1]);
        int delta = abs(x - xNow) + abs(y - yNow);
        if (delta <= l && (l - delta) % 2 == 0)
            return true;
    }
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    dx['L'] = -1;
    dx['R'] = 1;
    dy['U'] = 1;
    dy['D'] = -1;
    int n;
    scanf("%d\n%s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        xSum[i] = xSum[i - 1] + dx[s[i]];
        ySum[i] = ySum[i - 1] + dy[s[i]];
    }
    int x, y;
    scanf("%d%d", &x, &y);
    int left = 0, right = n, answer = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (Check(n, middle, x, y)) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    printf("%d\n", answer);
    return 0;
}