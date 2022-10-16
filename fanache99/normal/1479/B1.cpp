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

const int MAXN = 100000;
const int INF = 1000000000;

int tree[1 + 4 * (MAXN + 1)], lazy[1 + 4 * (MAXN + 1)];
int v[1 + MAXN];

void propagate(int node, int leftSon, int rightSon, int left, int middle, int right) {
    if (lazy[node]) {
        tree[leftSon] += lazy[node];
        tree[rightSon] += lazy[node];
        lazy[leftSon] += lazy[node];
        lazy[rightSon] += lazy[node];
        lazy[node] = 0;
    }
}

int query(int node, int left, int right, int from, int to) {
    if (from > to) {
        return -INF;
    }
    if (from <= left && right <= to) {
        return tree[node];
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node, leftSon, rightSon, left, middle, right);
    int answer = 0;
    if (from <= middle) {
        answer = max(answer, query(leftSon, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        answer = max(answer, query(rightSon, middle + 1, right, from, to));
    }
    return answer;
}

void add(int node, int left, int right, int from, int to, int value) {
    if (from <= left && right <= to) {
        tree[node] += value;
        lazy[node] += value;
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node, leftSon, rightSon, left, middle, right);
    if (from <= middle) {
        add(leftSon, left, middle, from, to, value);
    }
    if (middle + 1 <= to) {
        add(rightSon, middle + 1, right, from, to, value);
    }
    tree[node] = max(tree[leftSon], tree[rightSon]);
}

void change(int node, int left, int right, int where, int value) {
    if (left == right) {
        tree[node] = max(tree[node], value);
        lazy[node] = 0;
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node, leftSon, rightSon, left, middle, right);
    if (where <= middle) {
        change(leftSon, left, middle, where, value);
    } else {
        change(rightSon, middle + 1, right, where, value);
    }
    tree[node] = max(tree[leftSon], tree[rightSon]);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = max(max(query(1, 0, n, 0, v[i] - 1), query(1, 0, n, v[i] + 1, n)) + 1, query(1, 0, n, v[i], v[i]));
        if (v[i] != v[i - 1]) {
            add(1, 0, n, 0, n, 1);
        }
        change(1, 0, n, v[i - 1], x);
    }
    cout << query(1, 0, n, 0, n) << "\n";
    //timeDuration();
    return 0;
}