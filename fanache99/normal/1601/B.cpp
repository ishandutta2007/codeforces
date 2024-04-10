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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 300000;
const int INF = 1e9;

int a[1 + MAXN], b[1 + MAXN];
set<pair<int, int>> reach;
vector<int> slide[1 + MAXN];
int best[1 + MAXN], dad[1 + MAXN];
pair<int, int> tree[1 + 4 * MAXN];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = {left - a[left], left};
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

pair<int, int> query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[node];
    }
    int middle = (left + right) / 2;
    pair<int, int> ans = {INF, INF};
    if (from <= middle) {
        ans = min(ans, query(2 * node, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        ans = min(ans, query(2 * node + 1, middle + 1, right, from, to));
    }
    return ans;
}

void update(int node, int left, int right, int pos, int val) {
    if (left == right) {
        tree[node] = {val, left};
        return;
    }
    int middle = (left + right) / 2;
    if (pos <= middle) {
        update(2 * node, left, middle, pos, val);
    } else {
        update(2 * node + 1, middle + 1, right, pos, val);
    }
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        best[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        slide[i + b[i]].push_back(i);
    }
    build(1, 1, n);
    best[0] = dad[0] = a[0] = b[0] = 0;
    slide[0].push_back(0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto up : slide[node]) {
            while (true) {
                auto [jmp, down] = query(1, 1, n, up, n);
                if (jmp > up) {
                    break;
                }
                assert(best[down] == -1);
                best[down] = best[node] + 1;
                dad[down] = up;
                update(1, 1, n, down, INF);
                q.push(down);
            }
        }
    }
    if (best[n] == -1) {
        cout << "-1\n";
    } else {
        cout << best[n] << "\n";
        int x = n;
        for (int i = 1; i <= best[n]; i++) {
            x = dad[x];
            cout << x << " ";
            x += b[x];
        }
    }
    return 0;
}