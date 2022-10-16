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

int Ways(int sum, int n) {
    if (sum <= 2 || sum > n + n - 1)
        return 0;
    return min(n, sum / 2 - (1 - sum % 2)) - max(1, sum - n) + 1;
}

int main() {
    //sfreopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int suffix = 0, power10 = 1;
    while (1LL * suffix * 10 + 9 <= n + n - 1) {
        suffix = suffix * 10 + 9;
        power10 *= 10;
    }
    int answer = 0;
    for (int i = 0; i <= 9; i++)
        if (1LL * i * power10 + suffix <= n + n - 1)
            answer += Ways(i * power10 + suffix, n);
    printf("%d\n", answer);
    return 0;
}