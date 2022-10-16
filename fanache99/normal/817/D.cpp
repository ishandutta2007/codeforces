#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>

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

int v[1 + MAXN], big[1 + MAXN], small[1 + MAXN];
int rightBig[1 + MAXN], rightSmall[1 + MAXN];
int leftBig[1 + MAXN], leftSmall[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), topBig = 0, topSmall = 0;
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        v[i] = Read();
        while (topSmall && v[i] <= v[small[topSmall]]) {
            rightSmall[small[topSmall]] = i;
            topSmall--;
        }
        leftSmall[i] = small[topSmall];
        topSmall++;
        small[topSmall] = i;
        while (topBig && v[i] >= v[big[topBig]]) {
            rightBig[big[topBig]] = i;
            topBig--;
        }
        leftBig[i] = big[topBig];
        topBig++;
        big[topBig] = i;
    }
    while (topSmall) {
        rightSmall[small[topSmall]] = n + 1;
        topSmall--;
    }
    while (topBig) {
        rightBig[big[topBig]] = n + 1;
        topBig--;
    }
    for (int i = 1; i <= n; i++) {
        answer += 1LL * v[i] * (i - leftBig[i]) * (rightBig[i] - i);
        answer -= 1LL * v[i] * (i - leftSmall[i]) * (rightSmall[i] - i);
    }
    printf("%I64d\n", answer);
    return 0;
}