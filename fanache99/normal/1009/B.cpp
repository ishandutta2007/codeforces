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

char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ones = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '1')
            ones++;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
            continue;
        if (s[i] == '0') {
            printf("0");
            continue;
        }
        if (!found) {
            found = true;
            for (int j = 1; j <= ones; j++)
                printf("1");
        }
        printf("2");
    }
    if (!found)
        for (int j = 1; j <= ones; j++)
            printf("1");
    return 0;
}