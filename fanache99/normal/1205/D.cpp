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
#include <bitset>
#include <unordered_map>

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

const int MAXN = 1000;

vector<int> g[1 + MAXN];
int weight[1 + MAXN];

void DFS(int node, int father) {
    weight[node] = 1;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
        }
    }
}

int getCentroid(int n) {
    DFS(1, 0);
    for (int i = 1; i <= n; i++) {
        bool bad = false;
        for (auto j : g[i]) {
            if (weight[j] <= weight[i] && weight[j] > n / 2) {
                bad = true;
                break;
            }
        }
        if (n - weight[i] > n / 2) {
            bad = true;
        }
        if (!bad) {
            return i;
        }
    }
}

int dad[1 + MAXN], nodes[1 + MAXN];
int v[1 + MAXN], w[1 + MAXN];

void assign(int node, int father, int val, int &p, int t[]) {
    for (auto son : g[node]) {
        if (son != father) {
            p++;
            cout << son << " " << node << " " << t[p] - val << "\n";
            assign(son, node, t[p], p, t);
        }
    }
}

void solve(int root, int n) {
    DFS(root, 0);
    set<pair<int, int> > sizes;
    for (auto x : g[root]) {
        dad[x] = x;
        nodes[x] = weight[x];
        sizes.insert(make_pair(nodes[x], x));
    }
    while (sizes.size() > 2) {
        int a = (*sizes.begin()).second;
        sizes.erase(sizes.begin());
        int b = (*sizes.begin()).second;
        sizes.erase(sizes.begin());
        dad[a] = b;
        nodes[b] += nodes[a];
        sizes.insert(make_pair(nodes[b], b));
    }
    int x = (*sizes.begin()).second;
    sizes.erase(sizes.begin());
    int y = (*sizes.begin()).second;
    sizes.erase(sizes.begin());
    assert(nodes[x] >= n / 3 && nodes[y] >= n / 3);
    for (int i = 1; i <= nodes[x]; i++) {
        v[i] = i;
    }
    for (int i = 1; i <= nodes[y]; i++) {
        w[i] = i * (nodes[x] + 1);
    }
    int pv = 0, pw = 0;
    for (auto son : g[root]) {
        int p = son;
        while (dad[p] != p) {
            p = dad[p];
        }
        if (p == x) {
            pv++;
            cout << root << " " << son << " " << v[pv] << "\n";
            assign(son, root, v[pv], pv, v);
        } else {
            pw++;
            cout << root << " " << son << " " << w[pw] << "\n";
            assign(son, root, w[pw], pw, w);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        cout << "1 2 1\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = getCentroid(n);
    solve(root, n);
    //timeDuration();
    return 0;
}