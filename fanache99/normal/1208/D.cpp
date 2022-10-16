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
#include <unordered_map>

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

const int MAXN = 200000;
const long long INF = 1000000000000000000LL;

long long s[1 + MAXN];
int p[1 + MAXN];
long long tree[1 + 4 * MAXN], where[1 + 4 * MAXN], lazy[1 + 4 * MAXN];

void merge(int node) {
    int leftSon = 2 * node, rightSon = 2 * node + 1;
    if (tree[leftSon] < tree[rightSon]) {
        tree[node] = tree[leftSon];
        where[node] = where[leftSon];
    } else {
        tree[node] = tree[rightSon];
        where[node] = where[rightSon];
    }
}

void propagate(int node) {
    if (lazy[node] != 0) {
        int leftSon = 2 * node, rightSon = 2 * node + 1;
        tree[leftSon] += lazy[node];
        lazy[leftSon] += lazy[node];
        tree[rightSon] += lazy[node];
        lazy[rightSon] += lazy[node];
        lazy[node] = 0;
    }
}

void build(int node, int left, int right) {
    lazy[node] = 0;
    if (left == right) {
        tree[node] = s[left];
        where[node] = left;
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    build(leftSon, left, middle);
    build(rightSon, middle + 1, right);
    merge(node);
}

void update(int node, int left, int right, int from, int to, long long add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        tree[node] += add;
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node);
    if (from <= middle) {
        update(leftSon, left, middle, from, to, add);
    }
    if (middle + 1 <= to) {
        update(rightSon, middle + 1, right, from, to, add);
    }
    merge(node);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int x = where[1];
        p[x] = i;
        update(1, 1, n, x, x, INF);
        update(1, 1, n, x, n, -i);
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    //timeDuration();
    return 0;
}