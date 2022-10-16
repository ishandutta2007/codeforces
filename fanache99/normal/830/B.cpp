//#inlude <iostream>
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
#include <cstring>

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
const int MAXNODES = 262144;
const int INF = 1000000000;

int v[1 + MAXN];
int active[1 + MAXNODES], minimum[1 + MAXNODES];

void BuildTree(int node, int left, int right) {
    if (left == right) {
        active[node] = 1;
        minimum[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    active[node] = active[2 * node] + active[2 * node + 1];
    minimum[node] = min(minimum[2 * node], minimum[2 * node + 1]);
}

int GetMinimum(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return minimum[node];
    int middle = (left + right) / 2, answer = INF;
    if (from <= middle)
        answer = min(answer, GetMinimum(2 * node, left, middle, from, to));
    if (middle + 1 <= to)
        answer = min(answer, GetMinimum(2 * node + 1, middle + 1, right, from, to));
    return answer;
}

int GetActive(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return active[node];
    int middle = (left + right) / 2, answer = 0;
    if (from <= middle)
        answer += GetActive(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        answer += GetActive(2 * node + 1, middle + 1, right, from, to);
    return answer;
}

void Deactivate(int node, int left, int right, int where) {
    if (left == right) {
        minimum[node] = INF;
        active[node] = 0;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Deactivate(2 * node, left, middle, where);
    else
        Deactivate(2 * node + 1, middle + 1, right, where);
    active[node] = active[2 * node] + active[2 * node + 1];
    minimum[node] = min(minimum[2 * node], minimum[2 * node + 1]);
}

int Find(int node, int left, int right, int from, int to, int need) {
    if (from <= left && right <= to) {
        if (minimum[node] != need)
            return -1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (minimum[2 * node] == need) {
                right = middle;
                node = 2 * node;
            }
            else {
                left = middle + 1;
                node = 2 * node + 1;
            }
        }
        return left;
    }
    int middle = (left + right) / 2, answer = -1;
    if (from <= middle)
        answer = Find(2 * node, left, middle, from, to, need);
    if (answer != -1)
        return answer;
    return Find(2 * node + 1, middle + 1, right, from, to, need);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    BuildTree(1, 1, n);
    long long answer = 0;
    for (int i = 1, x = 0; i <= n; i++) {
        if (x == n)
            x = 0;
        int global = GetMinimum(1, 1, n, 1, n), local = GetMinimum(1, 1, n, x + 1, n);
        if (local != global) {
            answer += GetActive(1, 1, n, x + 1, n);
            x = 0;
        }
        int y = Find(1, 1, n, x + 1, n, global);
        answer += GetActive(1, 1, n, x + 1, y);
        Deactivate(1, 1, n, y);
        x = y;
    }
    printf("%I64d\n", answer);
    return 0;
}