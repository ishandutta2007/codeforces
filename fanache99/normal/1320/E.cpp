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

const int MAXN = 200000;
const int MAXLOG = 18;
const int INF = 1000000000;

vector<int> g[1 + MAXN];
vector<pair<int, int> > t[1 + MAXN];
int dad[1 + MAXLOG][1 + MAXN], answer[1 + MAXN], virusId[1 + MAXN];
int counter = 0, start[1 + MAXN], finish[1 + MAXN], depth[1 + MAXN];
int speed[1 + MAXN], id[1 + MAXN], virus[1 + MAXN], city[1 + MAXN], st[1 + MAXN];

void DFS(int node, int father) {
    dad[0][node] = father;
    depth[node] = depth[father] + 1;
    for (int i = 1; (1 << i) < depth[node]; i++) {
        dad[i][node] = dad[i - 1][dad[i - 1][node]];
    }
    start[node] = ++counter;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
        }
    }
    finish[node] = counter;
}

int raise(int node, int delta) {
    for (int i = 0; i < MAXLOG; i++) {
        if ((delta >> i) & 1) {
            node = dad[i][node];
        }
    }
    return node;
}

bool isParent(int a, int b) {
    return start[a] <= start[b] && finish[b] <= finish[a];
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    a = raise(a, depth[a] - depth[b]);
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (dad[i][a] != dad[i][b]) {
            a = dad[i][a];
            b = dad[i][b];
        }
    }
    if (a != b) {
        a = dad[0][a];
        b = dad[0][b];
    }
    return a;
}

inline bool compareStart(const int &a, const int &b) {
    return start[a] < start[b];
}

void sortUnique(vector<int> &v) {
    sort(v.begin(), v.end(), compareStart);
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

pair<int, int> d[1 + MAXN];

bool isSmaller(int c1, int s1, int c2, int s2) {
    int t1 = (c1 == 0 ? 0 : (c1 - 1) / speed[s1] + 1);
    int t2 = (c2 == 0 ? 0 : (c2 - 1) / speed[s2] + 1);
    return make_pair(t1, virusId[s1]) < make_pair(t2, virusId[s2]);
}

bool seen[1 + MAXN];

void dijkstra(vector<int> &v) {
    priority_queue<pair<pair<int, int>, pair<int, int> >, vector<pair<pair<int, int>, pair<int, int> > >, greater<pair<pair<int, int>, pair<int, int> > > > h;
    for (auto node : v) {
        if (virusId[node] != 0) {
            d[node] = {0, virusId[node]};
            h.push({{0, virusId[node]}, {node, 0}});
        } else {
            d[node] = {INF, 0};
        }
    }
    while (!h.empty()) {
        int r = h.top().first.first, s = h.top().first.second, node = h.top().second.first, c = h.top().second.second;
        h.pop();
        if (seen[node]) {
            continue;
        }
        seen[node] = true;
        for (auto it : t[node]) {
            int other = it.first, l = it.second;
            int r0 = (c + l - 1) / speed[s] + 1, s0 = s;
            if (make_pair(r0, s0) < d[other]) {
                d[other] = {r0, s0};
                h.push({{r0, s0}, {other, c + l}});
            }
        }
    }
}

void solve(int k, int m) {
    vector<int> v;
    for (int i = 1; i <= k; i++) {
        v.push_back(virus[i]);
    }
    for (int i = 1; i <= m; i++) {
        v.push_back(city[i]);
    }
    sortUnique(v);
    int x = v.size();
    for (int i = 0; i + 1 < x; i++) {
        v.push_back(lca(v[i], v[i + 1]));
    }
    sortUnique(v);
    int top = 1;
    st[top] = v[0];
    for (int i = 1; i < v.size(); i++) {
        int node = v[i];
        while (!isParent(st[top], node)) {
            top--;
        }
        int l = depth[node] - depth[st[top]];
        t[st[top]].push_back({node, l});
        t[node].push_back({st[top], l});
        top++;
        st[top] = node;
    }
    dijkstra(v);
    for (auto node : v) {
        seen[node] = false;
        t[node].clear();
        if (id[node] != 0) {
            answer[id[node]] = d[node].second;
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    speed[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int k, m;
        cin >> k >> m;
        for (int i = 1; i <= k; i++) {
            cin >> virus[i] >> speed[i];
            virusId[virus[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            cin >> city[i];
            id[city[i]] = i;
        }
        solve(k, m);
        for (int i = 1; i <= m; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= k; i++) {
            virusId[virus[i]] = 0;
        }
        for (int i = 1; i <= m; i++) {
            id[city[i]] = 0;
        }
    }
    //timeDuration();
    return 0;
}