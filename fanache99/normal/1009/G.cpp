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
const int SIGMA = 6;

char s[1 + MAXN];
int have[SIGMA], sum[1 << SIGMA], limit[1 << SIGMA];
int mask[1 + MAXN];
char answer[1 + MAXN];

void Modify(int mask, int add) {
    for (int i = 0; i < (1 << SIGMA); i++)
        limit[i] += add;
    mask = (1 << SIGMA) - 1 - mask;
    for (int subMask = mask; subMask; subMask = (mask & (subMask - 1)))
        limit[subMask] -= add;
}

bool Check() {
    for (int i = 0; i < SIGMA; i++)
        sum[1 << i] = have[i];
    for (int mask = 1; mask < (1 << SIGMA); mask++) {
        int bit = (mask & -mask);
        if (bit != mask)
            sum[mask] = sum[bit] + sum[mask - bit];
        if (sum[mask] > limit[mask])
            return false;
    }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        have[s[i] - 'a']++;
        mask[i] = (1 << SIGMA) - 1;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d %s", &x, s + 1);
        int l = strlen(s + 1);
        mask[x] = 0;
        for (int j = 1; j <= l; j++)
            mask[x] |= (1 << (s[j] - 'a'));
    }
    for (int i = 1; i <= n; i++)
        Modify(mask[i], 1);
    for (int i = 1; i <= n; i++) {
        Modify(mask[i], -1);
        for (int j = 0; j < SIGMA; j++)
            if ((mask[i] & (1 << j)) && have[j]) {
                have[j]--;
                if (Check()) {
                    answer[i] = j + 'a';
                    break;
                }
                else
                    have[j]++;
            }
        if (!answer[i]) {
            printf("Impossible\n");
            return 0;
        }
    }
    printf("%s\n", answer + 1);
    return 0;
}