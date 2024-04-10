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
const int MAXNODES = 262144;

int v[1 + MAXN];
long long dp[1 + MAXN];
deque<int> Deque;
int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, c;
    scanf("%d%d", &n, &c);
    if (c == 1) {
        printf("0\n");
        return 0;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (!Deque.empty() && v[i] <= v[Deque.back()])
            Deque.pop_back();
        Deque.push_back(i);
        while (!Deque.empty() && Deque.front() <= i - c)
            Deque.pop_front();
        if (i >= c)
            dp[i] = max(dp[i], dp[i - c] + v[Deque.front()]);
    }
    printf("%I64d\n", sum - dp[n]);
    return 0;
}