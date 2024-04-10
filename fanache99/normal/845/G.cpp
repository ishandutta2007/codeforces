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

const int MAXN = 100000;
const int MAXM = 100000;
const int MAXLOG = 60;

struct Edge {
    int a;
    int b;
    long long c;
};

vector<pair<int, long long> > g[1 + MAXN];
long long base[1 + MAXLOG];
long long d[1 + MAXN];
bool seen[1 + MAXN];

void add(long long value) {
    for (int bit = MAXLOG; bit >= 0; bit--) {
        if (value & (1LL << bit)) {
            if (base[bit]) {
                value ^= base[bit];
            } else {
                base[bit] = value;
                return;
            }
        }
    }
}

void DFS(int node) {
    seen[node] = true;
    for (auto it : g[node]) {
        if (!seen[it.first]) {
            d[it.first] = d[node] ^ it.second;
            DFS(it.first);
        } else {
            add(d[node] ^ d[it.first] ^ it.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //InputReader cin("input.txt");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    DFS(2);
    long long answer = d[n] ^ d[1];
    for (int bit = MAXLOG; bit >= 0; bit--) {
        if ((answer & (1LL << bit)) && base[bit]) {
            answer ^= base[bit];
        }
    }
    cout << answer << "\n";
    return 0;
}