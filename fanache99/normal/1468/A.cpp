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

const int MAXN = 500000;

struct Node {
    int best1;
    int best2;
    bool lazy;
};

Node tree[1 + 4 * (MAXN + 1)];

void propagate(int node) {
    if (tree[node].lazy) {
        tree[2 * node].best2 = max(tree[2 * node].best2, tree[2 * node].best1 + 1);
        tree[2 * node].lazy = true;
        tree[2 * node + 1].best2 = max(tree[2 * node + 1].best2, tree[2 * node + 1].best1 + 1);
        tree[2 * node + 1].lazy = true;
        tree[node].lazy = false;
    }
}

void update(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        tree[node].lazy = true;
        tree[node].best2 = max(tree[node].best2, tree[node].best1 + 1);
        return;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (from <= middle) {
        update(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        update(2 * node + 1, middle + 1, right, from, to);
    }
    tree[node].best1 = max(tree[2 * node].best1, tree[2 * node + 1].best1);
    tree[node].best2 = max(tree[2 * node].best2, tree[2 * node + 1].best2);
}

void change(int node, int left, int right, int where, int value) {
    if (left == right) {
        tree[node].best1 = value;
        return;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (where <= middle) {
        change(2 * node, left, middle, where, value);
    } else {
        change(2 * node + 1, middle + 1, right, where, value);
    }
    tree[node].best1 = max(tree[2 * node].best1, tree[2 * node + 1].best1);
    tree[node].best2 = max(tree[2 * node].best2, tree[2 * node + 1].best2);
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return max(tree[node].best1, tree[node].best2);
    }
    propagate(node);
    int middle = (left + right) / 2, answer = 0;
    if (from <= middle) {
        answer = max(answer, query(2 * node, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        answer = max(answer, query(2 * node + 1, middle + 1, right, from, to));
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //InputReader cin;
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= 4 * (n + 1); i++) {
            tree[i] = {0, 0, false};
        }
        change(1, 0, n, 0, 1);
        int answer = 1;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            int y = 1 + query(1, 0, n, 0, x);
            update(1, 0, n, 0, x);
            change(1, 0, n, x, y);
            answer = max(answer, query(1, 0, n, 0, n));
        }
        cout << answer - 1 << "\n";
    }
    return 0;
}