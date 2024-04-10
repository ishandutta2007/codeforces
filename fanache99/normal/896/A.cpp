#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>

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

const long long INFLL = 1000000000000000005LL;
const int MAXN = 100000;

char s[80] = " What are you doing at the end of the world? Are you busy? Will you save us?";
char a[80] = " What are you doing while sending  ";
char b[80] = "  ? Are you busy? Will you send  ";
long long l[1 + MAXN];

int aa;

char Solve(int n, long long k) {
    while (1) {
        if (k > l[n])
            return '.';
        if (n == 0)
            return s[k];
        if (k == l[n])
            return '?';
        if (k == l[n] - 1)
            return '"';
        if (k <= 34)
            return a[k];
        if (k <= 34 + l[n - 1]) {
            n--;
            k -= 34;
            continue;
        }
        if (k <= 34 + l[n - 1] + 32)
            return b[k - 34 - l[n - 1]];
        k -= 34 + l[n - 1] + 32;
        n--;
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    b[1] = a[34] = b[32] = '"';
    char ch = '"';
    //printf("%s%s%s%s%c?\n", a + 1, s + 1, b + 1, s + 1, ch);
    //printf("%d %d %d\n", strlen(s + 1), strlen(a + 1), strlen(b + 1));
    l[0] = 75;
    for (int i = 1; i <= MAXN; i++)
        l[i] = min(INFLL, 2 * l[i - 1] + 32 + 34 + 2);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int n;
        long long k;
        scanf("%d%I64d", &n, &k);
        printf("%c", Solve(n, k));
    }
    return 0;
}