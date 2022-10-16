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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXVAL = 1000000;
const int INF = 10000000;
const int MAXD = 7;

int low[1 + MAXVAL];
vector<int> d;
int mask[1 << MAXD], sign[1 << MAXD];

void Precompute(int n) {
    for (int i = 2; i <= n; i++)
        if (!low[i]) {
            low[i] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    low[j] = i;
        }
}

void Decompose(int n) {
    d.clear();
    while (n != 1) {
        int prime = low[n];
        d.push_back(prime);
        while (n % prime == 0)
            n /= prime;
    }
    mask[0] = sign[0] = 1;
    for (int i = 1; i < (1 << d.size()); i++)
        for (int j = 0; j < d.size(); j++)
            if (i & (1 << j)) {
                mask[i] = d[j] * mask[i ^ (1 << j)];
                sign[i] = -1 * sign[i ^ (1 << j)];
                break;
            }
}

int Count(int x) {
    int answer = 0;
    for (int i = 0; i < (1 << d.size()); i++)
        answer += sign[i] * (x / mask[i]);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    Precompute(MAXVAL);
    for (int test = 1; test <= tests; test++) {
        int x, p, k;
        scanf("%d%d%d", &x, &p, &k);
        int left = x + 1, right = INF, answer = INF;
        Decompose(p);
        while (left <= right) {
            int middle = (left + right) / 2;
            if (Count(middle) - Count(x) >= k) {
                answer = middle;
                right = middle - 1;
            }
            else
                left = middle + 1;
        }
        printf("%d\n", answer);
    }
    return 0;
}