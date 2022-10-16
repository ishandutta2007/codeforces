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
const int MAXN = 300000;
const int MAXNODES = 1048576;

int d[1 + MAXVAL];
int v[1 + MAXN];
int biggest[1 + MAXNODES];
long long sum[1 + MAXNODES];

void Sieve(int n) {
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            d[j]++;
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        biggest[node] = sum[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    biggest[node] = max(biggest[2 * node], biggest[2 * node + 1]);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

void Update(int node, int left, int right, int from, int to) {
    if (biggest[node] <= 2)
        return;
    if (left == right) {
        v[left] = d[v[left]];
        biggest[node] = sum[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Update(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right, from, to);
    biggest[node] = max(biggest[2 * node], biggest[2 * node + 1]);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

long long Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return sum[node];
    int middle = (left + right) / 2;
    long long answer = 0;
    if (from <= middle)
        answer += Query(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        answer += Query(2 * node + 1, middle + 1, right, from, to);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    Sieve(MAXVAL);
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    BuildTree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int type = Read(), a = Read(), b = Read();
        if (type == 1)
            Update(1, 1, n, a, b);
        else
            printf("%I64d\n", Query(1, 1, n, a, b));
    }
    return 0;
}