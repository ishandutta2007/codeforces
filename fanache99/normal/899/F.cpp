//#include <iostream>
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

const int MAXN = 200000;
const int MAXNODES = 524288;

char s[1 + MAXN];
unsigned long long mask[1 + MAXNODES];
int active[1 + MAXNODES];

int Code(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a';
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 26;
    return ch - '0' + 52;
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        mask[node] = 1LL << Code(s[left]);
        active[node] = 1;
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    mask[node] = mask[2 * node] | mask[2 * node + 1];
    active[node] = active[2 * node] + active[2 * node + 1];
}

int GetPosition(int node, int left, int right, int where) {
    if (left == right)
        return left;
    int middle = (left + right) / 2;
    if (active[2 * node] < where)
        return GetPosition(2 * node + 1, middle + 1, right, where - active[2 * node]);
    return GetPosition(2 * node, left, middle, where);
}

void Remove(int node, int left, int right, int from, int to, int bit) {
    if (!(mask[node] & (1LL << bit)))
        return;
    if (left == right) {
        mask[node] = active[node] = 0;
        return;
    }
        int middle = (left + right) / 2;
    if (left < from || to < right) {
        if (from <= middle)
            Remove(2 * node, left, middle, from, to, bit);
        if (middle + 1 <= to)
            Remove(2 * node + 1, middle + 1, right, from, to, bit);
    }
    else {
        Remove(2 * node, left, middle, from, to, bit);
        Remove(2 * node + 1, middle + 1, right, from, to, bit);
    }
    mask[node] = mask[2 * node] | mask[2 * node + 1];
    active[node] = active[2 * node] + active[2 * node + 1];
}

void DFS(int node, int left, int right) {
    if (left == right) {
        if (active[node])
            printf("%c", s[left]);
        return;
    }
    int middle = (left + right) / 2;
    DFS(2 * node, left, middle);
    DFS(2 * node + 1, middle + 1, right);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, q;
    scanf("%d%d\n%s", &n, &q, s + 1);
    BuildTree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        char c;
        scanf("%d%d %c", &a, &b, &c);
        a = GetPosition(1, 1, n, a);
        b = GetPosition(1, 1, n, b);
        Remove(1, 1, n, a, b, Code(c));
    }
    DFS(1, 1, n);
    return 0;
}