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

const int MOD = 1000000007;

vector<pair<long long, int> > events;
int total[3], newTotal[3], block[3], base[3][3], answer[3][3], temp[3][3];

void RaiseToPower(long long power) {
    memset(answer, 0, sizeof(answer));
    answer[0][0] = answer[1][1] = answer[2][2] = 1;
    while (power) {
        if (power % 2) {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    temp[i][j] = 0;
                    for (int k = 0; k < 3; k++)
                        temp[i][j] = (1LL * answer[i][k] * base[k][j] + temp[i][j]) % MOD;
                }
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    answer[i][j] = temp[i][j];
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    temp[i][j] = (1LL * base[i][k] * base[k][j] + temp[i][j]) % MOD;
            }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                base[i][j] = temp[i][j];
        power /= 2;
    }
}

void Move(long long steps) {
    memset(base, 0, sizeof(base));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (abs(i - j) <= 1 && !block[j])
                base[i][j] = 1;
    RaiseToPower(steps);
    for (int j = 0; j < 3; j++) {
        newTotal[j] = 0;
        for (int i = 0; i < 3; i++)
            newTotal[j] = (1LL * total[i] * answer[i][j] + newTotal[j]) % MOD;
    }
    for (int j = 0; j < 3; j++)
        total[j] = newTotal[j];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%I64d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int c;
        long long a, b;
        scanf("%d%I64d%I64d", &c, &a, &b);
        events.push_back(make_pair(a, c));
        events.push_back(make_pair(b + 1, -c));
    }
    events.push_back(make_pair(m + 1, 0));
    sort(events.begin(), events.end());
    long long where = 1, before = 0;
    total[0] = total[2] = 0;
    total[1] = 1;
    for (int i = 0; i < events.size(); i++) {
        long long x = events[i].first;
        int c = events[i].second;
        if (x != before) {
            Move(x - where - 1);
            where = x - 1;
        }
        if (c > 0)
            block[c - 1]++;
        else
            block[-c - 1]--;
        before = x;
    }
    printf("%d\n", total[1]);
    return 0;
}