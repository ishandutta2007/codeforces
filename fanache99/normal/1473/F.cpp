#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_set>

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
    inline InputReader &operator >>(long long &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 3000;
const int INF = 1000000000;

int a[1 + MAXN], b[1 + MAXN];
vector<short int> g[1 + MAXN + 1];
int fromCap[1 + MAXN], fromFlow[1 + MAXN];
int toCap[1 + MAXN], toFlow[1 + MAXN], leftSize = 0, rightSize = 0;
int leftNodes[1 + MAXN], rightNodes[1 + MAXN];
vector<vector<int> > flow;
int dad[1 + MAXN + 1];
bool seen[1 + MAXN + 1];

int getCap(int a, int b, int source, int sink) {
    if (a == source) {
        return fromCap[b];
    }
    if (b == source) {
        return 0;
    }
    if (b == sink) {
        return toCap[a];
    }
    if (a == sink) {
        return 0;
    }
    if (a <= leftSize) {
        return INF;
    } else {
        return 0;
    }
}

int getFlow(int a, int b, int source, int sink) {
    if (a == source) {
        return fromFlow[b];
    }
    if (b == source) {
        return -fromFlow[a];
    }
    if (b == sink) {
        return toFlow[a];
    }
    if (a == sink) {
        return -toFlow[b];
    }
    if (a <= leftSize) {
        return flow[a][b - leftSize];
    } else {
        return -flow[b][a - leftSize];
    }
}

void addFlow(int a, int b, int c, int source, int sink) {
    if (a == source) {
        fromFlow[b] += c;
        return;
    }
    if (b == source) {
        fromFlow[a] -= c;
        return;
    }
    if (b == sink) {
        toFlow[a] += c;
        return;
    }
    if (a == sink) {
        toFlow[b] -= c;
        return;
    }
    if (a <= leftSize) {
        flow[a][b - leftSize] += c;
    } else {
        flow[b][a - leftSize] -= c;
    }
}

bool BFS(int n, int source, int sink) {
    for (int i = 0; i <= n; i++) {
        seen[i] = false;
    }
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == sink) {
            continue;
        }
        for (auto other : g[node]) {
            if (!seen[other] && getCap(node, other, source, sink) > getFlow(node, other, source, sink)) {
                seen[other] = true;
                q.push(other);
                dad[other] = node;
            }
        }
    }
    return seen[sink];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int source = 0, sink = n + 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] >= 0) {
            sum += b[i];
            leftSize++;
            leftNodes[leftSize] = i;
        } else {
            rightSize++;
            rightNodes[rightSize] = i;
        }
    }
    flow.resize(leftSize + 1);
    for (int i = 1; i <= leftSize; i++) {
        flow[i].resize(rightSize + 1);
        for (int j = 1; j <= rightSize; j++) {
            flow[i][j] = 0;
            if (leftNodes[i] > rightNodes[j] && a[leftNodes[i]] % a[rightNodes[j]] == 0) {
                g[i].push_back(leftSize + j);
                g[leftSize + j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= leftSize; i++) {
        g[source].push_back(i);
        g[i].push_back(source);
        fromCap[i] = b[leftNodes[i]];
        fromFlow[i] = 0;
    }
    for (int i = 1; i <= rightSize; i++) {
        g[leftSize + i].push_back(sink);
        g[sink].push_back(leftSize + i);
        toCap[leftSize + i] = -b[rightNodes[i]];
        toFlow[leftSize + i] = 0;
    }
    long long flow = 0;
    while (BFS(n + 1, source, sink)) {
        for (int node = leftSize + 1; node <= leftSize + rightSize; node++) {
            if (seen[node] && getFlow(node, sink, source, sink) < getCap(node, sink, source, sink)) {
                dad[sink] = node;
                int add = INF;
                for (int node = sink; node != source; node = dad[node]) {
                    add = min(add, getCap(dad[node], node, source, sink) - getFlow(dad[node], node, source, sink));
                }
                if (add == 0) {
                    continue;
                }
                for (int node = sink; node != source; node = dad[node]) {
                    addFlow(dad[node], node, add, source, sink);
                }
                flow += add;
            }
        }
    }
    cout << sum - flow << "\n";
    return 0;
}