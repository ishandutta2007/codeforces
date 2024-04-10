#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
//#include "cup.h"

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

long long Try(int m, int b, int h) {
    int left = 0, right = m * b, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (b * m - middle >= h * m) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return 1LL * (answer + 1) * h * (h + 1) / 2 + 1LL * (h + 1) * answer * (answer + 1) / 2;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int m, b;
    scanf("%d%d", &m, &b);
    long long answer = 0;
    for (int i = 0; i <= b; i++)
        answer = max(answer, Try(m, b, i));
    printf("%I64d\n", answer);
    return 0;
}