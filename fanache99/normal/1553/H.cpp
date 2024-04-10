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

const int MAXK = 19;
const int INF = 1e7;

int v[1 + (1 << MAXK)];

struct Trie {
    Trie *son[2];

    Trie() {
        son[0] = son[1] = nullptr;
    }
};

Trie *root = new Trie();

void insert(int x, int k) {
    Trie *node = root;
    for (int i = k - 1; i >= 0; i--) {
        int b = ((x >> i) & 1);
        if (!node->son[b]) {
            node->son[b] = new Trie();
        }
        node = node->son[b];
    }
}

struct Ans {
    int mn;
    int mx;
    int ans;
};

vector<Ans> DFS(Trie *node, int k, int val) {
    if (k == -1) {
        return {{0, 0, INF}};
    }
    vector<Ans> l, r;
    if (node->son[0]) {
        l = DFS(node->son[0], k - 1, val);
    }
    if (node->son[1]) {
        r = DFS(node->son[1], k - 1, val | (1 << k));
    }
    vector<Ans> v;
    if (l.empty() || r.empty()) {
        vector<Ans> w = (l.empty() ? r : l);
        int b = (l.empty() ? (1 << k) : 0);
        assert(w.size() == (1 << k));
        for (int i = 0; i < (1 << k); i++) {
            v.push_back({w[i].mn ^ b, w[i].mx ^ b, w[i].ans});
        }
        for (int i = 0; i < (1 << k); i++) {
            v.push_back({w[i].mn ^ (1 << k) ^ b, w[i].mx ^ (1 << k) ^ b, w[i].ans});
        }
    } else {
        for (int i = 0; i < (1 << k); i++) {
            r[i].mn ^= (1 << k);
            r[i].mx ^= (1 << k);
        }
        for (int i = 0; i < (1 << k); i++) {
            v.push_back({l[i].mn, r[i].mx, min(min(l[i].ans, r[i].ans), r[i].mn - l[i].mx)});
        }
        for (int i = 0; i < (1 << k); i++) {
            v.push_back({r[i].mn ^ (1 << k), l[i].mx ^ (1 << k), min(min(l[i].ans, r[i].ans), (l[i].mn ^ (1 << k)) - (r[i].mx ^ (1 << k)))});
        }
    }
    return v;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        insert(v[i], k);
    }
    vector<Ans> v = DFS(root, k - 1, 0);
    assert(v.size() == (1 << k));
    for (int i = 0; i < (1 << k); i++) {
        cout << v[i].ans << " ";
    }
    return 0;
}