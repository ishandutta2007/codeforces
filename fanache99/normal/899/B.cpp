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

const int MAXN = 24;

int v[1 + MAXN];
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    bool leap = false;
    scanf("%d", &n);
    int where;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] == 29) {
            leap = true;
            where = i;
        }
    }
    if (leap) {
        int day = 1;
        bool bad = false;
        for (int i = where - 1; i >= 1; i--) {
            day = (day - 1 + 12) % 12;
            if (v[i] != days[day])
                bad = true;
        }
        day = 1;
        for (int i = where + 1; i <= n; i++) {
            day = (day + 1) % 12;
            if (v[i] != days[day])
                bad = true;
        }
        if (bad)
            printf("No\n");
        else
            printf("Yes\n");
        return 0;
    }
    for (int start = 0; start < 12; start++) {
        int day = start;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (v[i] != days[day])
                bad = true;
            day = (day + 1) % 12;
        }
        if (!bad) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}