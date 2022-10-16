//#inlude <iostream>
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
#include <cstring>

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

const int MAXN = 1000000;
const int SIGMA = 26;

char s[1 + MAXN];
int toLeft[1 + MAXN + 1], toRight[1 + MAXN + 1], last[1 + MAXN];
vector<int> now;

int FindLeft(int x) {
    if (toLeft[x] == x)
        return x;
    return toLeft[x] = FindLeft(toLeft[x]);
}

int FindRight(int x) {
    if (toRight[x] == x)
        return x;
    return toRight[x] = FindRight(toRight[x]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 0; i <= n + 1; i++)
        toLeft[i] = toRight[i] = i;
    for (int i = 1; i <= n; i++)
        if ((i != 1 && s[i] != s[i - 1]) || (i != n && s[i] != s[i + 1]))
            now.push_back(i);
    int answer = 0;
    while (!now.empty()) {
        answer++;
        for (auto &it : now) {
            toLeft[it] = FindLeft(it - 1);
            toRight[it] = FindRight(it + 1);
        }
        vector<int> after;
        for (auto &it : now) {
            int a = FindLeft(it), b = FindRight(it);
            if (a != 0)
                after.push_back(a);
            if (b != n + 1)
                after.push_back(b);
        }
        now.clear();
        for (auto &it : after)
            if (last[it] != answer) {
                last[it] = answer;
                int a = FindLeft(it - 1), b = FindRight(it + 1);
                if ((a != 0 && s[a] != s[it]) || (b != n + 1 && s[b] != s[it]))
                    now.push_back(it);
            }
    }
    printf("%d\n", answer);
    return 0;
}