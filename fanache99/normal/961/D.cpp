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

const int MAXN = 100000;

struct Point {
    int x;
    int y;
};

Point v[1 + MAXN], other[1 + MAXN];

bool Collinear(Point a, Point b, Point c) {
    return (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y == 0);
}

bool Try(Point a, Point b, int n) {
    int m = 0;
    for (int i = 1; i <= n; i++)
        if (!Collinear(a, b, v[i])) {
            m++;
            other[m] = v[i];
        }
    if (m <= 2)
        return true;
    for (int i = 3; i <= m; i++)
        if (!Collinear(other[1], other[2], other[i]))
            return false;
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i].x, &v[i].y);
    if (n <= 3) {
        printf("YES\n");
        return 0;
    }
    if (Try(v[1], v[2], n) || Try(v[1], v[3], n) || Try(v[2], v[3], n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}