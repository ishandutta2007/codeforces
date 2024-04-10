#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

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

const int MAXN = 200000;

int v[1 + MAXN + 1], toLeft[1 + MAXN + 1], toRight[1 + MAXN + 1], answer[1 + MAXN + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    toLeft[0] = toRight[n + 1] = n + 3;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] == 0)
            toLeft[i] = 0;
        else
            toLeft[i] = toLeft[i - 1] + 1;
    }
    for (int i = n; i >= 1; i--) {
        if (v[i] == 0)
            toRight[i] = 0;
        else
            toRight[i] = toRight[i + 1] + 1;
        answer[i] = min(toLeft[i], toRight[i]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}