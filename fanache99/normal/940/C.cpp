#include <fstream>
#include <iostream>
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

const int MAXN = 100000;
const int SIGMA = 26;

char s[1 + MAXN];
bool seen[SIGMA];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d\n%s", &n, &k, s + 1);
    for (int i = 1; i <= n; i++)
        seen[s[i] - 'a'] = true;
    int small = 0;
    while (!seen[small])
        small++;
    int big = SIGMA - 1;
    while (!seen[big])
        big--;
    if (n < k) {
        printf("%s", s + 1);
        for (int i = n + 1; i <= k; i++)
            printf("%c", small + 'a');
        return 0;
    }
    int j = k;
    while (s[j] - 'a' == big)
        j--;
    for (int i = 1; i < j; i++)
        printf("%c", s[i]);
    int x = s[j] - 'a' + 1;
    while (!seen[x])
        x++;
    printf("%c", x + 'a');
    for (int i = j + 1; i <= k; i++)
        printf("%c", small + 'a');
    return 0;
}