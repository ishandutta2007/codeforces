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

const int MAXN = 100000;

struct Lecture {
    int sa, ea, sb, eb;
};

Lecture v[1 + MAXN], v1[1 + MAXN], v2[1 + MAXN];
int m, tree[1 + 16 * MAXN], lazy[1 + 16 * MAXN];

void normalize(int n) {
    map<int, int> seen;
    for (int i = 1; i <= n; i++) {
        seen[v[i].sa] = seen[v[i].ea] = seen[v[i].sb] = seen[v[i].eb] = 1;
    }
    for (auto &it : seen) {
        it.second = ++m;
    }
    for (int i = 1; i <= n; i++) {
        v[i].sa = seen[v[i].sa];
        v[i].ea = seen[v[i].ea];
        v[i].sb = seen[v[i].sb];
        v[i].eb = seen[v[i].eb];
    }
}

void build(int node, int left, int right) {
    tree[node] = 0;
    lazy[node] = 0;
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    build(leftSon, left, middle);
    build(rightSon, middle + 1, right);
}

void propagate(int node) {
    if (lazy[node] != 0) {
        int leftSon = 2 * node, rightSon = 2 * node + 1;
        lazy[leftSon] += lazy[node];
        tree[leftSon] += lazy[node];
        lazy[rightSon] += lazy[node];
        tree[rightSon] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int from, int to, int add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        tree[node] += add;
        return;
    }
    propagate(node);
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    if (from <= middle) {
        update(leftSon, left, middle, from, to, add);
    }
    if (middle + 1 <= to) {
        update(rightSon, middle + 1, right, from, to, add);
    }
    tree[node] = max(tree[leftSon], tree[rightSon]);
}

int query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[node];
    }
    propagate(node);
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1, answer = 0;
    if (from <= middle) {
        answer = max(answer, query(leftSon, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        answer = max(answer, query(rightSon, middle + 1, right, from, to));
    }
    tree[node] = max(tree[leftSon], tree[rightSon]);
    return answer;
}

inline bool sCompare(const Lecture &a, const Lecture &b) {
    return a.sa < b.sa;
}

inline bool eCompare(const Lecture &a, const Lecture &b) {
    return a.ea < b.ea;
}

bool checkBad(int n) {
    for (int i = 1; i <= n; i++) {
        v1[i] = v[i];
        v2[i] = v[i];
    }
    sort(v1 + 1, v1 + n + 1, sCompare);
    sort(v2 + 1, v2 + n + 1, eCompare);
    build(1, 1, m);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && v2[j].ea < v1[i].sa) {
            update(1, 1, m, v2[j].sb, v2[j].eb, 1);
            j++;
        }
        if (query(1, 1, m, v1[i].sb, v1[i].eb) > 0) {
            return true;
        }
    }
    return false;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].sa >> v[i].ea >> v[i].sb >> v[i].eb;
    }
    normalize(n);
    bool bad = checkBad(n);
    for (int i = 1; i <= n; i++) {
        swap(v[i].sa, v[i].sb);
        swap(v[i].ea, v[i].eb);
    }
    bad |= checkBad(n);
    if (bad) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    //timeDuration();
    return 0;
}