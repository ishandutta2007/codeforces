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

const int MAXN = 200000;

int v[1 + MAXN];
pair<int, int> out[1 + MAXN];
int fenwick[1 + MAXN];

void Update(int x, int n, int add) {
    for (; x <= n; x += x & -x)
        fenwick[x] += add;
}

int Query(int x) {
    int answer = 0;
    for (; x; x -= x & -x)
        answer += fenwick[x];
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        out[i] = make_pair(v[i], i);
        Update(i, n, 1);
    }
    sort(out + 1, out + n + 1);
    long long answer = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && out[j].first < i) {
            Update(out[j].second, n, -1);
            j++;
        }
        answer += Query(min(i - 1, v[i]));
    }
    printf("%I64d\n", answer);
    return 0;
}