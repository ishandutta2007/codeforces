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
const int MAXLOG = 17;

int v[1 + MAXN];
pair<int, int> vn[1 + MAXN];
long long sum[1 + MAXN], active[1 + MAXN];

void Update(int x, int n, int add, long long fenwick[]) {
    for (; x <= n; x += (x & -x))
        fenwick[x] += add;
}

long long Query(int x, long long fenwick[]) {
    long long answer = 0;
    for (; x > 0; x -= (x & -x))
        answer += fenwick[x];
    return answer;
}

void Search(int &start, long long &answer, long long &have, int n) {
    start = 0;
    for (int step = (1 << MAXLOG); step >= 1; step /= 2)
        if (start + step <= n && sum[start + step] <= have) {
            have -= sum[start + step];
            answer += active[start + step];
            start += step;
        }
    start++;
    if (start == n + 1)
        start = 1;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    long long have;
    scanf("%d%I64d", &n, &have);
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        total += v[i];
        vn[i] = make_pair(v[i], i);
        Update(i, n, v[i], sum);
        Update(i, n, 1, active);
    }
    sort(vn + 1, vn + n + 1);
    int start = 1;
    long long answer = 0;
    for (int i = n; i >= 1; i--) {
        if (have >= vn[i].first) {
            answer += 1LL * i * (have / total);
            have %= total;
            long long suffix = Query(n, sum) - Query(start - 1, sum);
            if (suffix <= have) {
                have -= suffix;
                answer += Query(n, active) - Query(start - 1, active);
                Search(start, answer, have, n);
            }
            else {
                have += Query(start - 1, sum);
                answer -= Query(start - 1, active);
                Search(start, answer, have, n);
            }
        }
        Update(vn[i].second, n, -v[vn[i].second], sum);
        Update(vn[i].second, n, -1, active);
        total -= v[vn[i].second];
    }
    printf("%I64d\n", answer);
    return 0;
}