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
#include <complex>

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

const int MAXN = 100000;
const int INF = 1000000000;

int a[1 + MAXN], b[1 + MAXN];
map<int, int> best;

int Try(int n, int m, int x) {
    best.clear();
    for (int i = 1; i <= n; i++)
        best[a[i] % (2 * x)]++;
    for (int i = 1; i <= m; i++)
        best[(b[i] + x) % (2 * x)]++;
    int answer = 0;
    for (auto &it : best)
        answer = max(answer, it.second);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), y1 = Read();
    for (int i = 1; i <= n; i++)
        a[i] = Read();
    int m = Read(), y2 = Read();
    for (int i = 1; i <= m; i++)
        b[i] = Read();
    int answer = 2;
    for (int i = 1; i <= INF; i *= 2)
        answer = max(answer, Try(n, m, i));
    printf("%d\n", answer);
    return 0;
}