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
const int MAXVAL = 1000001;
const long long INF = 1000000000000000000LL;

pair<int, int> a[1 + MAXN], b[1 + MAXN];
pair<pair<int, int>, int> c[1 + MAXN];
long long tree[1 + 4 * MAXVAL], lazy[1 + 4 * MAXVAL];

void build(int node, int left, int right) {
    tree[node] = -INF;
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

void update(int node, int left, int right, int from, int to, long long add) {
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

long long query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[node];
    }
    propagate(node);
    int middle = (left + right) / 2, leftSon = 2 * node, rightSon = 2 * node + 1;
    long long answer = -INF;
    if (from <= middle) {
        answer = max(answer, query(leftSon, left, middle, from, to));
    }
    if (middle + 1 <= to) {
        answer = max(answer, query(rightSon, middle + 1, right, from, to));
    }
    tree[node] = max(tree[leftSon], tree[rightSon]);
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= p; i++) {
        cin >> c[i].first.first >> c[i].first.second >> c[i].second;
    }
    sort(c + 1, c + p + 1);
    build(1, 1, MAXVAL);
    for (int i = 1; i <= m; i++) {
        if (i > 1 && b[i].first == b[i - 1].first) {
            continue;
        }
        update(1, 1, MAXVAL, b[i].first, b[i].first, INF - b[i].second);
    }
    long long answer = -INF;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= p && c[j].first.first < a[i].first) {
            update(1, 1, MAXVAL, c[j].first.second + 1, MAXVAL, c[j].second);
            j++;
        }
        answer = max(answer, -a[i].second + query(1, 1, MAXVAL, 1, MAXVAL));
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}