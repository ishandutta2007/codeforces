//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXVAL = 100000;
const int MAXF = 6;

int low[1 + MAXVAL], dp[1 + MAXVAL];

void Sieve(int n) {
    for (int i = 2; i <= n; i++)
        if (!low[i]) {
            low[i] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    if (!low[j])
                        low[j] = i;
        }
}

int factors[1 + MAXF], factorCount;

void Decompose(int n) {
    factorCount = 0;
    while (n != 1) {
        int base = low[n];
        while (low[n] == base)
            n /= base;
        factorCount++;
        factors[factorCount] = base;
    }
}

int main() {
    Sieve(MAXVAL);
    int n, answer = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Decompose(x);
        int current = 1;
        for (int i = 1; i <= factorCount; i++)
            current = max(current, dp[factors[i]] + 1);
        answer = max(answer, current);
        for (int i = 1; i <= factorCount; i++)
            dp[factors[i]] = max(dp[factors[i]], current);
    }
    cout << answer << "\n";
    return 0;
}