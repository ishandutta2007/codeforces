
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

const int MOD = 1000000007;
const int MAXK = 1000;

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

int dp[1 + MAXK][1 + MAXK];
int preffix[1 + 2 * MAXK];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    int s = a + b, ia = RaiseToPower(a, MOD - 2), ib = RaiseToPower(b, MOD - 2), is = RaiseToPower(s, MOD - 2);
    int pa = (1LL * a * is) % MOD, pb = (1LL * b * is) % MOD, answer = 0, ipa = RaiseToPower(pa, MOD - 2), ipb = RaiseToPower(pb, MOD - 2);
    int z = (1LL * a * s) % MOD;
    z = (1LL * z * ib) % MOD;
    z = (1LL * z * ib) % MOD;
    preffix[0] = 0;
    for (int i = 1, power = pa; i <= 2 * k; i++) {
        preffix[i] = (1LL * i * power + preffix[i - 1]) % MOD;
        power = (1LL * power * pa) % MOD;
    }
    dp[1][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < k; j++) {
            if (j >= i)
                dp[i][j] = (1LL * pb * dp[i][j - i] + dp[i][j]) % MOD;
            if (i > 1)
                dp[i][j] = (1LL * pa * dp[i - 1][j] + dp[i][j]) % MOD;
            if (i + j < k) {
                int p = (1LL * dp[i][j] * pb) % MOD;
                int r = k - i - j, x, y;
                if (r <= i) {
                    x = j + 2 * i;
                    y = 0;
                }
                else {
                    x = k;
                    y = r - i;
                }
                int e = (z - preffix[x - 1] + MOD) % MOD;
                p = (1LL * p * e) % MOD;
                p = (1LL * p * pb) % MOD;
                if (x - y >= 0)
                    p = (1LL * p * RaiseToPower(ipa, x - y)) % MOD;
                else
                    p = (1LL * p * RaiseToPower(pa, y - x)) % MOD;
                answer = (answer + p) % MOD;
            }
        }
    int x = k, y = k - 1;
    int e = (z - preffix[x - 1] + MOD) % MOD;
    int p = (1LL * pb * e) % MOD;
    p = (1LL * p * ipa) % MOD;
    answer = (answer + p) % MOD;
    printf("%d\n", answer);
    return 0;
}