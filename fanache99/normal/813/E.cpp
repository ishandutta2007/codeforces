#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

vector<int> seen[1 + MAXN];
vector<int> tree[1 + MAXNODES];
int limit[1 + MAXN];

void BuildTree(int node, int left, int right) {
    if (left == right) {
        if (limit[left])
            tree[node].push_back(limit[left]);
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    int i = 0, j = 0;
    while (i < tree[2 * node].size() && j < tree[2 * node + 1].size())
        if (tree[2 * node][i] < tree[2 * node + 1][j]) {
            tree[node].push_back(tree[2 * node][i]);
            i++;
        }
        else {
            tree[node].push_back(tree[2 * node + 1][j]);
            j++;
        }
    while (i < tree[2 * node].size()) {
        tree[node].push_back(tree[2 * node][i]);
        i++;
    }
    while (j < tree[2 * node + 1].size()) {
        tree[node].push_back(tree[2 * node + 1][j]);
        j++;
    }
}

int from, to, k;

int Query(int node, int left, int right) {
    if (from <= left && right <= to) {
        int low = 0, high = tree[node].size() - 1, answer = 0;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (tree[node][middle] >= from) {
                high = middle - 1;
                answer = tree[node].size() - middle;
            }
            else
                low = middle + 1;
        }
        return answer;
    }
    int middle = (left + right) / 2, answer = 0;
    if (from <= middle)
        answer += Query(2 * node, left, middle);
    if (middle + 1 <= to)
        answer += Query(2 * node + 1, middle + 1, right);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    k = Read();
    for (int i = 1; i <= n; i++) {
        int x = Read();
        seen[x].push_back(i);
    }
    for (int i = 1; i <= MAXN; i++)
        for (int j = k; j < seen[i].size(); j++)
            limit[seen[i][j]] = seen[i][j - k];
    BuildTree(1, 1, n);
    int answer = 0, q = Read();
    for (int i = 1; i <= q; i++) {
        int x = Read(), y = Read();
        from = ((x + answer) % n) + 1;
        to = ((y + answer) % n) + 1;
        if (from > to)
            swap(from, to);
        answer = (to - from + 1) - Query(1, 1, n);
        printf("%d\n", answer);
    }
    return 0;
}