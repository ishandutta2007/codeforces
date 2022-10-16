#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

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

int Gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, gcd = 0, answer = 0, odd = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        gcd = Gcd(gcd, x);
        if (x % 2)
            odd++;
        else {
            answer += (odd / 2) + 2 * (odd % 2);
            odd = 0;
        }
    }
    answer += (odd / 2) + 2 * (odd % 2);
    if (gcd != 1)
        printf("YES\n0\n");
    else
        printf("YES\n%d\n", answer);
    return  0;
}