#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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

long long power10 = 1, first;

bool Lucky(long long n) {
    int digits = 0;
    while (n) {
        power10 *= 10;
        first = n % 10;
        if (n % 10)
            digits++;
        n /= 10;
    }
    power10 /= 10;
    if (digits == 1)
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n;
    scanf("%I64d", &n);
    n++;
    if (Lucky(n)) {
        printf("1\n");
        return 0;
    }
    printf("%I64d\n", (first + 1) * power10 - n + 1);
    return 0;
}