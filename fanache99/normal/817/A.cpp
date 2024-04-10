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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long x1, y1, x2, y2, x, y;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2, &x, &y);
    long long dx = x2 - x1, dy = y2 - y1;
    if ((dx % x) || (dy % y)) {
        printf("NO\n");
        return 0;
    }
    dx /= x;
    dy /= y;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    if (dx < dy)
        swap(dx, dy);
    if ((dx - dy) % 2)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}