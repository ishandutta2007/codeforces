//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;
const int MOD = 1000000007;

char s[1 + MAXN];
int factorial[1 + MAXN], inverse[1 + MAXN];

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void Precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = RaiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int Combinations(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}


int Count(int a, int b) {
    if (!b)
        return 0;
    return Combinations(a + b, b - 1);
}

int main() {
    Precompute(MAXN);
    cin >> s + 1;
    int n = strlen(s + 1), closed = 0, open = 0, answer = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == ')')
            closed++;
    for (int i = 1; i <= n; i++)
        if (s[i] == ')')
            closed--;
        else {
            answer += Count(open, closed);
            if (answer >= MOD)
                answer -= MOD;
            open++;
        }
    cout << answer << "\n";
    return 0;
}