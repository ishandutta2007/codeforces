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
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

const int MAXN = 1000000;

struct Interval {
    int a;
    int b;
    int c;

    bool operator < (const Interval &other) const {
        return a < other.a || (a == other.a && b < other.b);
    }
};

set<Interval> s;
long long add[1 + MAXN];
int n;
long long fenwick[1 + MAXN];

void update(int x, long long add) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x] += add;
    }
}

long long query(int x) {
    long long ans = 0;
    for (; x > 0; x -= (x & -x)) {
        ans += fenwick[x];
    }
    return ans;
}

void change(int a, int b, int c1, int c2) {
    long long val = add[c1] - add[c2];
    update(a, val);
    update(b + 1, -val);
}

void changeCol(int l, int r, int d) {
    auto it = s.lower_bound({l, 0});
    if (it != s.begin()) {
        auto jt = prev(it);
        assert(jt->a < l);
        if (jt->b >= l) {
            int a = jt->a, b = jt->b, c = jt->c;
            s.erase(jt);
            s.insert({a, l - 1, c});
            s.insert({l, b, c});
        }
    }

    it = s.lower_bound({r + 1, 0});
    if (it != s.begin()) {
        auto jt = prev(it);
        assert(jt->a <= r);
        if (jt->b > r) {
            int a = jt->a, b = jt->b, c = jt->c;
            s.erase(jt);
            s.insert({a, r, c});
            s.insert({r + 1, b, c});
        }
    }

    while (true) {
        it = s.lower_bound({l, 0});
        if (it == s.end() || it->a > r) {
            break;
        }
        int a = it->a, b = it->b, c = it->c;
        s.erase(it);
        change(a, b, c, d);
    }

    s.insert({l, r, d});
}

long long answer(int x) {
    auto it = s.lower_bound({x + 1, 0});
    assert(it != s.begin());
    it = prev(it);
    return add[it->c] + query(x);
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    s.insert({1, n, 1});
    for (int i = 1; i <= q; i++) {
        string s;
        cin >> s;
        if (s == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            changeCol(l, r, c);
        } else if (s == "Add") {
            int c, x;
            cin >> c >> x;
            add[c] += x;
        } else if (s == "Query") {
            int x;
            cin >> x;
            cout << answer(x) << "\n";
        } else {
            assert(false);
        }
    }
    return 0;
}