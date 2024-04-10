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

const int MAXN = 200000;
const int MAXLOG = 20;

int v[1 + MAXN];
vector<int> g[1 + MAXN];
int sum[1 + MAXN], depth[1 + MAXN];
int moment[1 + MAXN];
int dad[1 + MAXN][1 + MAXLOG];

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    dad[node][0] = father;
    for (int i = 1; i <= MAXLOG; i++) {
        dad[node][i] = dad[dad[node][i - 1]][i - 1];
    }
    for (auto son : g[node]) {
        DFS(son, node);
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
    if (a == b) {
        return a;
    }
    for (int i = MAXLOG; i >= 0; i--) {
        if (dad[a][i] != dad[b][i]) {
            a = dad[a][i];
            b = dad[b][i];
        }
    }
    return dad[a][0];
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        moment[b] = i + 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!moment[i]) {
            root = i;
            break;
        }
    }
    DFS(root, 0);
    for (int i = 1; i < n; i++) {
        int a = v[i], b = v[i + 1];
        if (a == b) {
            sum[1]++;
        } else {
            int c = lca(a, b);
            int from = 1;
            if (a != c) {
                from = max(from, moment[raise(a, depth[a] - depth[c] - 1)]);
            }
            if (b != c) {
                from = max(from, moment[raise(b, depth[b] - depth[c] - 1)]);
            }
            sum[from]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        sum[i] += sum[i - 1];
        cout << n - 1 - sum[i] << "\n";
    }
    //timeDuration();
    return 0;
}