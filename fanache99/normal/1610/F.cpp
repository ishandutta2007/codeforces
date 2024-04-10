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

    inline InputReader &operator>>(int &n) {
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

const int MAXN = 400000;
const int MAXM = 400000;

int a[1 + MAXM + MAXN], b[1 + MAXM + MAXN], c[1 + MAXM + MAXN];
int other[1 + MAXM + MAXN][2], ans[1 + MAXM + MAXN];
int sum[1 + MAXN];
vector<int> adj[1 + MAXN];

void addClosure(int n, int &m) {
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 == 1) {
            odd.push_back(i);
        }
    }
    assert(odd.size() % 2 == 0);
    for (int i = 0; i < odd.size(); i += 2) {
        int x = odd[i], y = odd[i + 1];
        m++;
        a[m] = x;
        b[m] = y;
        c[m] = 1;
        adj[x].push_back(m);
        adj[y].push_back(m);
    }
}

void matchOne(int x, int y, int node) {
    if (a[x] == node) {
        other[x][0] = y;
    } else {
        assert(b[x] == node);
        other[x][1] = y;
    }
    if (a[y] == node) {
        other[y][0] = x;
    } else {
        assert(b[y] == node);
        other[y][1] = x;
    }
}

void match(vector<int> &e, int node) {
    while (e.size() >= 2) {
        int x = e.back(); e.pop_back();
        int y = e.back(); e.pop_back();
        matchOne(x, y, node);
    }
}

void matchAdj(int x) {
    vector<int> one, two;
    for (auto e : adj[x]) {
        if (c[e] == 1) {
            one.push_back(e);
        } else {
            two.push_back(e);
        }
    }
    match(one, x);
    match(two, x);
    if (!one.empty()) {
        assert(!two.empty() && one.size() == 1 && two.size() == 1);
        matchOne(one.back(), two.back(), x);
    }
}

void DFS(int edge, int o) {
    if (ans[edge] != 0) {
        assert(ans[edge] == o);
        return;
    }
    ans[edge] = o;
    int node = (o == 1 ? b[edge] : a[edge]);
    int newEdge = (o == 1 ? other[edge][1] : other[edge][0]);
    int newO = (node == a[newEdge] ? 1 : 2);
    DFS(newEdge, newO);
}

void orient(int n, int m) {
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 0) {
            DFS(i, 1);
        }
    }
}

int checkSum[1 + MAXN];

void check(int n, int m) {
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 1) {
            checkSum[a[i]] += c[i];
            checkSum[b[i]] -= c[i];
        } else {
            checkSum[a[i]] -= c[i];
            checkSum[b[i]] += c[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] % 2 == 1) {
            assert(checkSum[i] == 1 || checkSum[i] == -1);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int mInit = m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sum[a[i]] += c[i];
        sum[b[i]] += c[i];
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
    }
    addClosure(n, m);
    for (int i = 1; i <= n; i++) {
        matchAdj(i);
    }
    orient(n, m);
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] % 2 == 1) {
            odd++;
        }
    }
    cout << odd << "\n";
    for (int i = 1; i <= mInit; i++) {
        cout << ans[i];
    }
    check(n, mInit);
    return 0;
}