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

const int MAXN = 2000;

char a[1 + MAXN][1 + MAXN], b[1 + MAXN][1 + MAXN];
int sum[1 + MAXN];

int Do(int n, int m, int k, char s[1 + MAXN][1 + MAXN]) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            sum[j] = sum[j - 1] + (s[i][j] == '*');
            if (j >= k && sum[j] == sum[j - k])
                answer++;
        }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", a[i] + 1);
        for (int j = 1; j <= m; j++)
            b[j][i] = a[i][j];
    }
    int answer = 0;
    if (k <= m)
        answer += Do(n, m, k, a);
    if (k != 1 && k <= n)
        answer += Do(m, n, k, b);
    printf("%d\n", answer);
    return 0;
}