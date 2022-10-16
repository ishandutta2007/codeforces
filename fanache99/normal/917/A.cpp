#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
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

const int MAXN = 5000;

char s[1 + MAXN];
short int open[1 + MAXN][1 + MAXN], closed[1 + MAXN][1 + MAXN], sumOpen[1 + MAXN], sumClosed[1 + MAXN];

int Open(char ch) {
    if (ch == '(')
        return 1;
    if (ch == ')')
        return -1;
    return 1;
}

int Closed(char ch) {
    if (ch == '(')
        return 1;
    if (ch == ')')
        return -1;
    return -1;
}

void Precompute(int n) {
    for (int i = 1; i <= n; i++) {
        sumOpen[i] = sumOpen[i - 1] + Open(s[i]);
        sumClosed[i] = sumClosed[i - 1] + Closed(s[i]);
    }
    for (int i = 1; i <= n; i++) {
        open[i][i] = Open(s[i]);
        closed[i][i] = Closed(s[i]);
        for (int j = i + 1; j <= n; j++) {
            open[i][j] = min(open[i][j - 1], (short int) (sumOpen[j] - sumOpen[i - 1]));
            closed[i][j] = min(closed[i][j - 1], (short int) (sumClosed[j] - sumClosed[i - 1]));
        }
    }
}

int Deque[1 + MAXN];

int Check(int x, int l, int haveOpen, int haveClosed, int start, int finish) {
    if (haveOpen > l / 2 || haveClosed > l / 2)
        return 0;
    if (haveOpen + haveClosed == l)
        if (open[x][x + l - 1] >= 0)
            return 1;
        else
            return 0;
    if (haveOpen == l / 2)
        if (closed[x][x + l - 1] >= 0)
            return 1;
        else
            return 0;
    if (open[x][Deque[start + l / 2 - haveOpen - 1]] < 0)
        return 0;
    if (Deque[start + l / 2 - haveOpen - 1] == x + l - 1)
        return 1;
    if (closed[Deque[start + l / 2 - haveOpen - 1] + 1][x + l - 1] + sumOpen[Deque[start + l / 2 - haveOpen - 1]] - sumOpen[x - 1] >= 0)
        return 1;
    else
        return 0;
}

int Solve(int n) {
    int answer = 0;
    for (int l = 2; l <= n; l += 2) {
        int start = 1, finish = 0;
        int open = 0, closed = 0;
        for (int i = 1; i <= l; i++)
            if (s[i] == '(')
                open++;
            else
                if (s[i] == ')')
                    closed++;
                else {
                    finish++;
                    Deque[finish] = i;
                }
        answer += Check(1, l, open, closed, start, finish);
        for (int i = l + 1; i <= n; i++) {
            if (s[i] == '(')
                open++;
            else
                if (s[i] == ')')
                    closed++;
                else {
                    finish++;
                    Deque[finish] = i;
                }
            if (s[i - l] == '(')
                open--;
            else
                if (s[i - l] == ')')
                    closed--;
                else
                    start++;
            answer += Check(i - l + 1, l, open, closed, start, finish);
        }
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    Precompute(n);
    int answer = Solve(n);
    printf("%d\n", answer);
    return 0;
}