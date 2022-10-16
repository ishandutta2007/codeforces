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

const int MAXN = 100000;

struct Node {
    long long sum;
    long long mn, mx;
    long long mnPref, mxPref;
    long long mnSuf, mxSuf;

    Node(int val = 0) {
        sum = val;
        mn = mnPref = mnSuf = min(0, val);
        mx = mxPref = mxSuf = max(0, val);
    }
};

int a[1 + MAXN], b[1 + MAXN];
Node tree[1 + 4 * MAXN];

Node combine(Node l, Node r) {
    Node ans;
    ans.sum = l.sum + r.sum;
    ans.mnPref = min(l.mnPref, l.sum + r.mnPref);
    ans.mnSuf = min(r.mnSuf, r.sum + l.mnSuf);
    ans.mxPref = max(l.mxPref, l.sum + r.mxPref);
    ans.mxSuf = max(r.mxSuf, r.sum + l.mxSuf);
    ans.mn = min(min(l.mn, r.mn), l.mnSuf + r.mnPref);
    ans.mx = max(max(l.mx, r.mx), l.mxSuf + r.mxPref);
    return ans;
}

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = Node(a[left] - b[left]);
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

Node answer;
bool init;

void query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        if (!init) {
            init = true;
            answer = tree[node];
        } else {
            answer = combine(answer, tree[node]);
        }
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle) {
        query(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        query(2 * node + 1, middle + 1, right, from, to);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        init = false;
        query(1, 1, n, a, b);
        if (answer.sum != 0) {
            cout << "-1\n";
        } else {
            cout << max(answer.mx, -answer.mn) << "\n";
        }
    }
    return 0;
}