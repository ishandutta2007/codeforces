//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MOD = 1000000007;

long long Phi(long long n) {
    long long answer = n;
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            answer /= d;
            answer *= (d - 1);
        }
    if (n != 1) {
        answer /= n;
        answer *= (n - 1);
    }
    return answer;
}

int main() {
    long long n, k;
    cin >> n >> k;
    k = (k - 1) / 2 + 1;
    for (int i = 1; i <= k; i++) {
        if (n == 1) {
            cout << "1\n";
            return 0;
        }
        n = Phi(n);
    }
    cout << n % MOD << "\n";
    return 0;
}