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

const int MAXN = 1000000;
const int MOD = 1000000009;
const int BASE = 73;
const int MAXLOG = 21;

char s[1 + 2 * MAXN];
int power[1 + 2 * MAXN], code[1 + 2 * MAXN + 1], sum[1 + 2 * MAXN + 1];

void Precompute(int n) {
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (1LL * power[i - 1] * BASE) % MOD;
        code[i] = (1LL * code[i - 1] * BASE + (s[i] == '(' ? 1 : 2)) % MOD;
    }
}

bool Same(int x, int y, int l) {
    int code1 = (code[x + l - 1] - (1LL * code[x - 1] * power[l]) % MOD + MOD) % MOD;
    int code2 = (code[y + l - 1] - (1LL * code[y - 1] * power[l]) % MOD + MOD) % MOD;
    return (code1 == code2);
}

deque<int> Deque;

bool Smaller(int x, int y, int n) {
    for (int step = MAXLOG; step >= 0; step--)
        if ((1 << step) <= n && Same(x, y, 1 << step)) {
            x += (1 << step);
            y += (1 << step);
            n -= (1 << step);
        }
    if (!n)
        return false;
    if (s[x] == '(' && s[y] == ')')
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1), open = 0, closed = 0;
    for (int i = 1; i <= n; i++) {
        s[i + n] = s[i];
        if (s[i] == '(')
            open++;
        else
            closed++;
    }
    Precompute(2 * n);
    int where = 0;
    if (open >= closed) {
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
            while (!Deque.empty() && sum[i] <= sum[Deque.back()])
                Deque.pop_back();
            Deque.push_back(i);
        }
        for (int i = n; i <= 2 * n; i++) {
            while (!Deque.empty() && Deque.front() < i - n + 1)
                Deque.pop_front();
            sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
            while (!Deque.empty() && sum[i] <= sum[Deque.back()])
                Deque.pop_back();
            Deque.push_back(i);
            if (sum[Deque.front()] - sum[i - n] >= 0)
                if (!where)
                    where = i - n + 1;
                else
                    if (Smaller(i - n + 1, where, n))
                        where = i - n + 1;
        }
        for (int i = where; i < where + n; i++)
            printf("%c", s[i]);
        for (int i = 1; i <= open - closed; i++)
            printf(")");
    }
    else {
        for (int i = 2 * n; i > n; i--) {
            sum[i] = sum[i + 1] + (s[i] == ')' ? 1 : -1);
            while (!Deque.empty() && sum[i] <= sum[Deque.back()])
                Deque.pop_back();
            Deque.push_back(i);
        }
        for (int i = n + 1; i > 1; i--) {
            while (!Deque.empty() && Deque.front() > i + n - 1)
                Deque.pop_front();
            sum[i] = sum[i + 1] + (s[i] == ')' ? 1 : -1);
            while (!Deque.empty() && sum[i] <= sum[Deque.back()])
                Deque.pop_back();
            Deque.push_back(i);
            if (sum[Deque.front()] - sum[i + n] >= 0)
                if (!where)
                    where = i;
                else
                    if (Smaller(i, where, n))
                        where = i;
        }
        for (int i = 1; i <= closed - open; i++)
            printf("(");
        for (int i = where; i < where + n; i++)
            printf("%c", s[i]);
    }
    return 0;
}