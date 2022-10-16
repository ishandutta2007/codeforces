#include <bits/stdc++.h>

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = SIZE - 1;
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
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
const int MAXM = MAXN + 2;

struct Edge {
    int a;
    int b;
};

Edge e[1 + MAXM];
int dad[1 + MAXN], h[1 + MAXN];
char ans[1 + MAXM + 1];

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

bool join(int a, int b) {
    a = findDad(a), b = findDad(b);
    if (a == b) {
        return false;
    }
    if (h[a] > h[b]) {
        dad[b] = a;
    } else {
        if (h[a] == h[b]) {
            h[b]++;
        }
        dad[a] = b;
    }
    return true;
}

bool bad(vector<int> &out) {
    vector<int> nodes;
    for (auto eId : out) {
        nodes.push_back(e[eId].a);
        nodes.push_back(e[eId].b);
    }
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
    return out.size() == 3 && nodes.size() == 3;
}

int up[1 + MAXN];
vector<pair<int, int>> g[1 + MAXN];

void DFS(int node, int father, const vector<int> &out) {
    up[node] = father;
    for (auto [son, eId] : g[node]) {
        if (son != father && eId != out[0] && eId != out[1] && eId != out[2]) {
            DFS(son, node, out);
        }
    }
}

int main() {
//    InputReader cin = InputReader();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            dad[i] = i;
            h[i] = 1;
            g[i].clear();
        }
        vector<int> out;
        for (int i = 1; i <= m; i++) {
            cin >> e[i].a >> e[i].b;
            g[e[i].a].push_back({e[i].b, i});
            g[e[i].b].push_back({e[i].a, i});
            if (join(e[i].a, e[i].b)) {
                ans[i] = '0';
            } else {
                out.push_back(i);
                ans[i] = '1';
            }
        }
        assert(out.size() == m - (n - 1));
        if (bad(out)) {
            auto [a, b] = e[out[0]];
            DFS(a, 0, out);
            int c = up[b];
            assert(c != a);
            bool found = false;
            for (int i = 1; i <= m && !found; i++) {
                if ((e[i].a == c && e[i].b == b) || (e[i].a == b && e[i].b == c)) {
                    assert(i != out[0]);
                    found = true;
                    ans[i] = '1';
                    ans[out[0]] = '0';
                }
            }
            assert(found);
        }
        ans[m + 1] = 0;
        cout << (ans + 1) << "\n";
    }
    return 0;
}