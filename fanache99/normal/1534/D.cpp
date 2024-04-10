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

const int MAXN = 2000;

int d[1 + MAXN], dr[1 + MAXN], queries = 0;
bool in[1 + MAXN];
vector<pair<int, int> > edges;

void ask(int node, int n) {
    queries++;
    assert(queries <= (n + 1) / 2);
    cout << "? " << node << "\n";
    cout.flush();
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
}

void answer(int n) {
    assert(edges.size() == n - 1);
    cout << "!\n";
    for (auto it : edges) {
        cout << it.first << " " << it.second << "\n";
    }
    cout.flush();
}

vector<int> findDepth(int n, int k) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (d[i] == k) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    ask(1, n);
    int total = 1;
    in[1] = true;
    for (int i = 1; i <= n; i++) {
        dr[i] = d[i];
    }
    for (int i = 0; i < n - 1; i++) {
        vector<int> v = findDepth(n, i);
        if (v.size() != 1) {
            break;
        }
        vector<int> u = findDepth(n, i + 1);
        for (auto node : u) {
            edges.push_back({node, v[0]});
            in[node] = true;
            total++;
        }
    }
    while (total < n) {
        int best = n + 1, x;
        for (int i = 1; i <= n; i++) {
            if (!in[i] && dr[i] < best) {
                x = i;
                best = dr[i];
            }
        }
        ask(x, n);
        in[x] = true;
        total++;
        for (int i = 0; i < n - 1; i++) {
            vector<int> v = findDepth(n, i);
            int r = 0, f = 0;
            for (auto node : v) {
                if (dr[node] == dr[x] + i) {
                    f++;
                    r = node;
                }
            }
            if (f != 1) {
                break;
            }
            vector<int> u = findDepth(n, i + 1);
            for (auto node : u) {
                if (dr[node] == dr[x] + i + 1 || (dr[node] + 1 == dr[x] && i == 0)) {
                    edges.push_back({node, r});
                    if (!in[node]) {
                        in[node] = true;
                        total++;
                    }
                }
            }
        }
        vector<int> v = findDepth(n, 1);
        if (v.size() == 1) {
            vector<int> u = findDepth(n, 2);
            for (auto node : u) {
                if (!in[node]) {
                    in[node] = true;
                    total++;
                    edges.push_back({v[0], node});
                }
            }
        }

    }
    answer(n);
    return 0;
}