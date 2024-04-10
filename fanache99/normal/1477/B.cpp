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

const int MAXN = 200000;

char s[1 + MAXN], f[1 + MAXN];
int sum[1 + 4 * MAXN], lazy[1 + 4 * MAXN];

void build(int node, int left, int right) {
    lazy[node] = 0;
    if (left == right) {
        sum[node] = (f[left] == '1' ? 1 : -1);
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    build(leftSon, left, middle);
    build(rightSon, middle + 1, right);
    sum[node] = sum[leftSon] + sum[rightSon];
}

void propagate(int node, int leftSon, int rightSon, int left, int middle, int right) {
    if (lazy[node]) {
        sum[leftSon] = lazy[node] * (middle - left + 1);
        sum[rightSon] = lazy[node] * (right - middle);
        lazy[leftSon] = lazy[rightSon] = lazy[node];
        lazy[node] = 0;
    }
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return sum[node];
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node, leftSon, rightSon, left, middle, right);
    int answer = 0;
    if (from <= middle) {
        answer += query(leftSon, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        answer += query(rightSon, middle + 1, right, from, to);
    }
    return answer;
}

void update(int node, int left, int right, int from, int to, int value) {
    if (from <= left && right <= to) {
        sum[node] = value * (right - left + 1);
        lazy[node] = value;
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    propagate(node, leftSon, rightSon, left, middle, right);
    if (from <= middle) {
        update(leftSon, left, middle, from, to, value);
    }
    if (middle + 1 <= to) {
        update(rightSon, middle + 1, right, from, to, value);
    }
    sum[node] = sum[leftSon] + sum[rightSon];
}

int l[1 + MAXN], r[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, q;
        cin >> n >> q >> (s + 1) >> (f + 1);
        build(1, 1, n);
        for (int i = 1; i <= q; i++) {
            cin >> l[i] >> r[i];
        }
        bool bad = false;
        for (int i = q; i >= 1; i--) {
            int s = query(1, 1, n, l[i], r[i]);
            if (s == 0) {
                bad = true;
                break;
            }
            int value = (s > 0 ? 1 : -1);
            update(1, 1, n, l[i], r[i], value);
        }
        if (bad) {
            cout << "NO\n";
        } else {
            for (int i = 1; i <= n; i++) {
                if (query(1, 1, n, i, i) != (s[i] == '1' ? 1 : -1)) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    //timeDuration();
    return 0;
}