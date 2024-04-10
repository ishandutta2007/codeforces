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

const int MAXN = 30;
const long long INF = 1000000000000000000LL;

long long cost[MAXN];
bool ok[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &cost[i]);
    long long answer = INF;
    while (n >= 1 && 1 << (n - 1) >= l) {
        answer = min(answer, cost[n - 1]);
        n--;
    }
    if (!n) {
        printf("%I64d\n", answer);
        return 0;
    }
    long long sum = 0;
    ok[0] = true;
    int last = 0;
    for (int i = 1; i < n; i++)
        if (cost[last] * (1 << (i - last)) > cost[i]) {
            ok[i] = true;
            last = i;
        }
    for (int i = n - 1; i >= 0; i--)
        if (ok[i]) {
            answer = min(answer, sum + cost[i] * ((l - 1) / (1 << i) + 1));
            sum += cost[i] * (l / (1 << i));
            l -= (l / (1 << i)) * (1 << i);
            if (!l)
                break;
        }
    printf("%I64d\n", answer);
    return 0;
}