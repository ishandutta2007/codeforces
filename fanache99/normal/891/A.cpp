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
#include <cassert>

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
    int answer = 0, sign = 1;
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

const int MAXN = 2000;

int v[1 + MAXN];

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
    int n, gcd = 0, notOnes = 0;
    bool found = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        gcd = Gcd(gcd, v[i]);
        if (v[i] == 1)
            found = true;
        else
            notOnes++;
    }
    if (found) {
        printf("%d\n", notOnes);
        return 0;
    }
    if (gcd != 1) {
        printf("-1\n");
        return 0;
    }
    int answer = n;
    for (int i = 1; i <= n; i++) {
        gcd = 0;
        for (int j = i; j <= n; j++) {
            gcd = Gcd(gcd, v[j]);
            if (gcd == 1) {
                answer = min(answer, j - i);
                break;
            }
        }
    }
    printf("%d\n", answer + n - 1);
    return 0;
}