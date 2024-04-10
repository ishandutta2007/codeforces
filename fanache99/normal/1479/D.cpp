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

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
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

const int MAXN = 300000;
const int MAXLOG = 20;

int v[1 + MAXN];
unsigned long long code[1 + MAXN];

unsigned long long genCode() {
    return ((unsigned long long) rand() << 32) + rand();
}

void generateCodes(int n) {
    for (int i = 1; i <= n; i++) {
        code[i] = genCode();
    }
}

int n;
vector<int> g[1 + MAXN];

int dad[1 + MAXN][1 + MAXLOG];
int depth[1 + MAXN], root[1 + MAXN];
unsigned long long hashSum[1 + MAXLOG * MAXN];
int leftSon[1 + MAXLOG * MAXN], rightSon[1 + MAXLOG * MAXN];
int nodeCount = 0;

int createNode(int node) {
    nodeCount++;
    leftSon[nodeCount] = leftSon[node];
    rightSon[nodeCount] = rightSon[node];
    return nodeCount;
}

int update(int oldNode, int left, int right, int where) {
    int newNode = createNode(oldNode);
    if (left == right) {
        hashSum[newNode] = hashSum[oldNode] ^ code[left];
        return newNode;
    }
    int middle = (left + right) / 2;
    if (where <= middle) {
        leftSon[newNode] = update(leftSon[oldNode], left, middle, where);
    } else {
        rightSon[newNode] = update(rightSon[oldNode], middle + 1, right, where);
    }
    hashSum[newNode] = hashSum[leftSon[newNode]] ^ hashSum[rightSon[newNode]];
    return newNode;
}

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    dad[node][0] = father;
    for (int i = 1; (1 << i) < depth[node]; i++) {
        dad[node][i] = dad[dad[node][i - 1]][i - 1];
    }
    root[node] = update(root[father], 1, n, v[node]);
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
        }
    }
}

int raise(int node, int delta) {
    for (int i = 0; i <= MAXLOG; i++) {
        if (delta & (1 << i)) {
            node = dad[node][i];
        }
    }
    return node;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    a = raise(a, depth[a] - depth[b]);
    for (int i = MAXLOG; i >= 0; i--) {
        if (dad[a][i] != dad[b][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    }
    if (a != b) {
        a = dad[a][0];
    }
    return a;
}

unsigned long long getHash(int node1, int node2, int left, int right, int x) {
    return hashSum[node1] ^ hashSum[node2] ^ ((left <= x && x <= right) ? code[x] : 0);
}

int query(int node1, int node2, int left, int right, int from, int to, int x) {
    if (from <= left && right <= to) {
        unsigned long long h = getHash(node1, node2, left, right, x);
        if (h == 0) {
            return -1;
        } else {
            while (left != right) {
                int middle = (left + right) / 2;
                h = getHash(leftSon[node1], leftSon[node2], left, middle, x);
                if (h != 0) {
                    node1 = leftSon[node1];
                    node2 = leftSon[node2];
                    right = middle;
                } else {
                    node1 = rightSon[node1];
                    node2 = rightSon[node2];
                    left = middle + 1;
                }
            }
            return left;
        }
    }
    int middle = (left + right) / 2, answer = -1;
    if (from <= middle) {
        answer = query(leftSon[node1], leftSon[node2], left, middle, from, to, x);
    }
    if (middle + 1 <= to && answer == -1) {
        answer = query(rightSon[node1], rightSon[node2], middle + 1, right, from, to, x);
    }
    return answer;
}

int main() {
    timeBegin();
    //InputReader cin("input.txt");
    //ofstream cout("greutati.out");
    srand(time(0));
    int q;
    cin >> n >> q;
    generateCodes(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= q; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        int c = lca(a, b);
        cout << query(root[a], root[b], 1, n, l, r, v[c]) << "\n";
    }
    //timeDuration();
    return 0;
}