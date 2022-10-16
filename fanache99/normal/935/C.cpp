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
#include <cassert>

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
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    double r, x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= r * r)
        printf("%.10f %.10f %.10f\n", x1, y1, r);
    else
        if (x1 == x2 && y1 == y2)
            printf("%.10f %.10f %.10f\n", x1, y1 + r * 0.5, r * 0.5);
        else {
            double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            double k = ((d + r) * 0.5 - d) / d;
            printf("%.10f %.10f %.10f\n", (k + 1) * x1 - k * x2, (k + 1) * y1 - k * y2, (d + r) * 0.5);
        }
    return 0;
}