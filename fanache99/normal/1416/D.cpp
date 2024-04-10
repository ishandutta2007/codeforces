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

const int MAXN = 200000;
const int MAXM = 300000;
const int MAXQ = 500000;

int p[1 + MAXN];
pair<int, int> edge[1 + MAXM], op[1 + MAXQ];
bool out[1 + MAXM], seen[1 + MAXN];
int dad[1 + MAXN];
vector<int> nodes[1 + MAXN];
vector<pair<int, int> > events;

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        nodes[i].emplace_back(i);
    }
}

int findDad(int node) {
    if (dad[node] == node) {
        return dad[node];
    }
    return dad[node] = findDad(dad[node]);
}

inline bool compareP(const int &a, const int &b) {
    return p[a] < p[b];
}

void addEdge(int a, int b, int t) {
    a = findDad(a);
    b = findDad(b);
    if (a != b) {
        if (nodes[a].size() > nodes[b].size()) {
            swap(a, b);
        }
        events.emplace_back(make_pair(t, a));
        for (auto node : nodes[a]) {
            nodes[b].emplace_back(node);
            dad[node] = b;
        }
        sort(nodes[a].begin(), nodes[a].end(), compareP);
    }
}

void undo(int root) {
    for (auto node : nodes[root]) {
        dad[node] = root;
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("papagali.out");
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    for (int i = 1; i <= q; i++) {
        cin >> op[i].first >> op[i].second;
        if (op[i].first == 2) {
            out[op[i].second] = true;
        }
    }
    initialize(n);
    for (int i = 1; i <= m; i++) {
        if (!out[i]) {
            addEdge(edge[i].first, edge[i].second, q + 1);
        }
    }
    for (int i = q; i >= 1; i--) {
        if (op[i].first == 2) {
            addEdge(edge[op[i].second].first, edge[op[i].second].second, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dad[i] == i) {
            sort(nodes[i].begin(), nodes[i].end(), compareP);
        }
    }
    for (int i = 1; i <= q; i++) {
        while (!events.empty() && events.back().first < i) {
            undo(events.back().second);
            events.pop_back();
        }
        if (op[i].first == 1) {
            int node = findDad(op[i].second);
            while (!nodes[node].empty() && (dad[nodes[node].back()] != node || seen[nodes[node].back()])) {
                nodes[node].pop_back();
            }
            if (!nodes[node].empty()) {
                cout << p[nodes[node].back()] << "\n";
                seen[nodes[node].back()] = true;
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}