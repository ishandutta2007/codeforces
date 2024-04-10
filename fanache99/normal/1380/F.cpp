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
const int MOD = 998244353;

char c[1 + MAXN];
int tree[1 + 4 * MAXN][2][2];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int multiply(int x, int y) {
    return 1LL * x * y % MOD;
}

int one(int x) {
    return x + 1;
}

int two(int x) {
    if (x >= 10 && x <= 18) {
        return 18 - x + 1;
    } else {
        return 0;
    }
}

void leaf(int node, int pos) {
    tree[node][0][0] = one(c[pos]);
    tree[node][0][1] = tree[node][1][0] = 1;
    tree[node][1][1] = 0;
}

void combine(int node, int left, int right) {
    int middle = (left + right) / 2;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            tree[node][a][b] = 0;
            addTo(tree[node][a][b], multiply(tree[2 * node][a][0], tree[2 * node + 1][0][b]));
            addTo(tree[node][a][b], multiply(multiply(tree[2 * node][a][1], tree[2 * node + 1][1][b]), two(c[middle] * 10 + c[middle + 1])));
        }
    }
}

void build(int node, int left, int right) {
    if (left == right) {
        leaf(node, left);
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    combine(node, left, right);
}

void update(int node, int left, int right, int pos) {
    if (left == right) {
        leaf(node, pos);
        return;
    }
    int middle = (left + right) / 2;
    if (pos <= middle) {
        update(2 * node, left, middle, pos);
    } else {
        update(2 * node + 1, middle + 1, right, pos);
    }
    combine(node, left, right);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m;
    cin >> n >> m >> (c + 1);
    for (int i = 1; i <= n; i++) {
        c[i] -= '0';
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        c[x] = y;
        update(1, 1, n, x);
        cout << tree[1][0][0] << "\n";
    }
    //timeDuration();
    return 0;
}