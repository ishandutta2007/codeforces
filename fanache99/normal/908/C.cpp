//#include <iostream>
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

const int MAXN = 1000;

int x[1 + MAXN];
double y[1 + MAXN];

int Abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    int r;
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        y[i] = r;
        for (int j = 1; j < i; j++)
            if (Abs(x[i] - x[j]) <= 2 * r)
                y[i] = max(y[i], y[j] + sqrt((double) (-(x[i] - x[j]) * (x[i] - x[j]) + 4 * r * r)));
        printf("%.10f ", y[i]);
    }
    return 0;
}