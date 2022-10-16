#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int MOD = 1000000007;

int RaiseToPower(int base, long long power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n, m;
    int k;
    scanf("%I64d%I64d%d", &n, &m, &k);
    if (k == -1 && n % 2 != m % 2) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", RaiseToPower(RaiseToPower(2, m - 1), n - 1));
    return 0;
}