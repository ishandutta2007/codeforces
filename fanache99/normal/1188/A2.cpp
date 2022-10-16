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
const int MAXVAL = 1000000000;

vector<pair<int, int> > g[1 + MAXN];
int leaf[1 + MAXN], dad[1 + MAXN], val[1 + MAXN], need[1 + MAXN], depth[1 + MAXN];

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    if (g[node].size() == 1) {
        leaf[node] = node;
    } else {
        for (auto son : g[node]) {
            if (son.first != father) {
                dad[son.first] = node;
                val[son.first] = 0;
                need[son.first] = son.second;
                DFS(son.first, node);
                leaf[node] = leaf[son.first];
            }
        }
    }
}

struct Op {
    int a;
    int b;
    int x;
};

vector<Op> sol;

void add(int a, int b, int x) {
    sol.push_back({a, b, x});
    assert(-MAXVAL <= x && x <= MAXVAL);
    while (a != b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        val[a] += x;
        a = dad[a];
    }
}

void solve(int node, int father, int l0) {
    vector<int> leaves;
    if (l0 != 0) {
        leaves.push_back(l0);
    }
    for (auto it : g[node]) {
        int son = it.first;
        if (son != father) {
            leaves.push_back(leaf[son]);
            if (leaves.size() == 3) {
                break;
            }
        }
    }
    for (auto it : g[node]) {
        int son = it.first;
        if (son != father) {
            int x = need[son] - val[son];
            assert(x % 2 == 0);
            int l = leaf[son], l1 = leaves[0], l2 = leaves[1];
            if (l == leaves[0]) {
                l1 = leaves[2];
            } else if (l == leaves[1]) {
                l2 = leaves[2];
            }
            add(l, l1, x / 2);
            add(l, l2, x / 2);
            add(l1, l2, -x / 2);
            solve(son, node, l1);
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
    for (int i = 1; i < n; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        g[a].push_back({b, x});
        g[b].push_back({a, x});
    }
    if (n == 2) {
        cout << "YES\n1\n1 2 " << g[1][0].second << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    int root;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }
    DFS(root, 0);
    solve(root, 0, 0);
    for (int i = 1; i <= n; i++) {
        assert(val[i] == need[i]);
    }
    cout << sol.size() << "\n";
    for (auto it : sol) {
        cout << it.a << " " << it.b << " " << it.x << "\n";
    }
    //timeDuration();
    return 0;
}