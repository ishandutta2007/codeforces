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
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

const int MAXN = 150000;
const int MAXVAL = 1000010;

int v[1 + MAXN];
int low[1 + MAXVAL];
vector<int> g[1 + MAXN + MAXVAL];
int comp[1 + MAXN + MAXVAL], compId = 0;

void precompute() {
    for (int i = 2; i <= MAXVAL; i++) {
        if (low[i] == 0) {
            for (int j = i; j <= MAXVAL; j += i) {
                if (low[j] == 0) {
                    low[j] = i;
                }
            }
        }
    }
}

vector<int> decompose(int x) {
    vector<int> ps;
    while (x > 1) {
        int p = low[x];
        while (low[x] == p) {
            x /= p;
        }
        ps.push_back(p);
    }
    return ps;
}

void DFS(int node) {
    comp[node] = compId;
    for (auto it : g[node]) {
        if (comp[it] == 0) {
            DFS(it);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    precompute();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vector<int> ps = decompose(v[i]);
        for (auto p : ps) {
            g[i].push_back(n + p);
            g[n + p].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            compId++;
            DFS(i);
        }
    }
    set<pair<int, int> > s;
    for (int i = 1; i <= n; i++) {
        vector<int> ps = decompose(v[i] + 1);
        vector<int> comps = {comp[i]};
        for (auto p : ps) {
            comps.push_back(comp[p + n]);
        }
        sort(comps.begin(), comps.end());
        comps.resize(unique(comps.begin(), comps.end()) - comps.begin());
        for (int i = 0; i < comps.size(); i++) {
            for (int j = i + 1; j < comps.size(); j++) {
                s.insert({comps[i], comps[j]});
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        a = comp[a];
        b = comp[b];
        if (a > b) {
            swap(a, b);
        }
        if (a == b) {
            cout << "0\n";
        } else if (s.find({a, b}) != s.end()) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}