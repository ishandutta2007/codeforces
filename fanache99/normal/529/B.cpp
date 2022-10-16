#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>
#include <map>

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

const int MAXVAL = 1000;
const int MAXN = 1000;

int height[1 + MAXN], width[1 + MAXN], fat[1 + MAXN];

inline bool Compare(const int &a, const int &b) {
    return width[a] - height[a] > width[b] - height[b];
}

int Try(int h, int n) {
    int w = 0, lie = 0;
    fat[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (width[i] > h && height[i] > h)
            return MAXVAL * MAXVAL * MAXVAL;
        if (height[i] >= width[i])
            if (height[i] <= h)
                w += width[i];
            else {
                w += height[i];
                lie++;
            }
        else
            if (width[i] > h)
                w += width[i];
            else {
                fat[0]++;
                fat[fat[0]] = i;
                w += width[i];
            }
    }
    if (lie > n / 2)
        return MAXVAL * MAXVAL * MAXVAL;
    sort(fat + 1, fat + fat[0] + 1, Compare);
    for (int i = 1; i <= fat[0] && lie < n / 2; i++, lie++)
        w += height[fat[i]] - width[fat[i]];
    return w * h;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &width[i], &height[i]);
    int answer = MAXVAL * MAXVAL * MAXVAL;
    for (int h = 1; h <= MAXVAL; h++)
        answer = min(answer, Try(h, n));
    printf("%d\n", answer);
    return 0;
}