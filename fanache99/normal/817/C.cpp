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

bool Check(long long n, long long s) {
    int sum = 0;
    long long x = n;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    if (x - sum >= s)
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n, s;
    scanf("%I64d%I64d\n", &n, &s);
    long long left = 1, right = n, answer = n + 1;
    while (left <= right) {
        long long middle = (left + right) / 2;
        if (Check(middle, s)) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    printf("%I64d\n", n - answer + 1);
    return 0;
}