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

const int MAXN = 100000;

vector<int> g[1 + MAXN], gt[1 + MAXN], scc[1 + MAXN];
vector<int> order;
bool seen[1 + MAXN];
vector<int> component[1 + MAXN];
int id[1 + MAXN], inDegree[1 + MAXN];

bool query(int a, int b) {
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    bool answer;
    cin >> answer;
    return answer;
}

void answer(int node) {
    cout << "! " << node << "\n";
    cout.flush();
    exit(0);
}

void DFS(int node) {
    seen[node] = true;
    for (auto neighbour : g[node]) {
        if (!seen[neighbour]) {
            DFS(neighbour);
        }
    }
    order.push_back(node);
}

void antiDFS(int node, int componentId) {
    seen[node] = false;
    id[node] = componentId;
    component[componentId].push_back(node);
    for (auto neighbour : gt[node]) {
        if (seen[neighbour]) {
            antiDFS(neighbour, componentId);
        }
    }
}

void eliminate(int node, set<int> &start) {
    assert(node == component[id[node]].back());
    component[id[node]].pop_back();
    if (component[id[node]].empty()) {
        start.erase(id[node]);
        for (auto other : scc[id[node]]) {
            inDegree[other]--;
            if (inDegree[other] == 0) {
                start.insert(other);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    for (int node = 1; node <= n; node++) {
        if (!seen[node]) {
            DFS(node);
        }
    }
    reverse(order.begin(), order.end());
    int components = 0;
    for (auto node : order) {
        if (seen[node]) {
            antiDFS(node, ++components);
        }
    }
    if (components == 1) {
        answer(1);
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            if (id[i] != id[j]) {
                scc[id[i]].push_back(id[j]);
            }
        }
    }
    for (int i = 1; i <= components; i++) {
        sort(scc[i].begin(), scc[i].end());
        scc[i].resize(unique(scc[i].begin(), scc[i].end()) - scc[i].begin());
        for (auto j : scc[i]) {
            inDegree[j]++;
        }
    }
    set<int> start;
    for (int i = 1; i <= components; i++) {
        if (inDegree[i] == 0) {
            start.insert(i);
        }
    }
    int root = component[*start.begin()].back();
    while (start.size() > 1) {
        int other;
        if (id[root] == (*start.begin())) {
            other = component[*(next(start.begin()))].back();
        } else {
            other = component[*start.begin()].back();
        }
        if (query(root, other)) {
            eliminate(other, start);
        } else {
            eliminate(root, start);
            root = other;
        }
    }
    answer(root);
    //timeDuration();
    return 0;
}