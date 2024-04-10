//#include <iostream>
#include <fstream>
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

const int MAXROOT = 1000000;

long long Gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool Power3(long long x) {
    long long left = 1, right = MAXROOT, answer = MAXROOT;
    while (left <= right) {
        long long middle = (left + right) / 2;
        if (middle * middle * middle >= x) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    if (answer * answer * answer == x)
        return true;
    else
        return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        long long a, b;
        scanf("%I64d%I64d\n", &a, &b);
        long long x = Gcd(a, b), y = a * b / x;
        if (x * x % y != 0 || !Power3(a * b))
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}