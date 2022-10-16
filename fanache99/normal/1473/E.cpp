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

const int MAXN = 200000;
const long long INF = 1000000000000000000LL;

vector<pair<int, int> > g[1 + MAXN];
long long best[1 + MAXN][2][2];

struct Node {
    int node;
    int a;
    int b;
    long long cost;

    bool operator < (const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                best[i][a][b] = INF;
            }
        }
    }
    best[1][0][0] = 0;
    priority_queue<Node> h;
    h.push({1, 0, 0, 0});
    while (!h.empty()) {
        int node = h.top().node, a = h.top().a, b = h.top().b;
        long long cost = h.top().cost;
        h.pop();
        if (cost != best[node][a][b]) {
            continue;
        }
        for (auto it : g[node]) {
            int other = it.first, c = it.second;
            if (cost + c < best[other][a][b]) {
                best[other][a][b] = cost + c;
                h.push({other, a, b, cost + c});
            }
            if (a == 0 && cost < best[other][1][b]) {
                best[other][1][b] = cost;
                h.push({other, 1, b, cost});
            }
            if (b == 0 && cost + 2 * c < best[other][a][1]) {
                best[other][a][1] = cost + 2 * c;
                h.push({other, a, 1, cost + 2 * c});
            }
            if (a == 0 && b == 0 && cost + c < best[other][1][1]) {
                best[other][1][1] = cost + c;
                h.push({other, 1, 1, cost + c});
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << best[i][1][1] << " ";
    }
    return 0;
}