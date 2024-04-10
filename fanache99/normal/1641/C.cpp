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

const int MAXN = 200000;

set<int> maybe;
set<int> sick[1 + MAXN];
int n;
int dad[1 + MAXN], mn[1 + MAXN], mx[1 + MAXN];
bool out[1 + MAXN];

int findDad(int x) {
    if (dad[x] == x) {
        return x;
    }
    return dad[x] = findDad(dad[x]);
}

void join(int a, int b) {
    a = findDad(a);
    b = findDad(b);

    if (sick[a].size() > sick[b].size()) {
        swap(a, b);
    }
    for (auto it : sick[a]) {
        sick[b].insert(it);
    }
    mn[b] = min(mn[b], mn[a]);
    mx[b] = max(mx[b], mx[a]);
    dad[a] = b;
}

void makeNotSick(int x) {
    maybe.erase(x);
    out[x] = true;
    if (x > 1 && out[x - 1]) {
        join(x, x - 1);
    }
    if (x < n && out[x + 1]) {
        join(x, x + 1);
    }
}

void updNotSick(int a, int b) {
    while (true) {
        auto it = maybe.lower_bound(a);
        if (it == maybe.end() || *it > b) {
            break;
        }
        makeNotSick(*it);
    }
}

void updSick(int a, int b) {
    a = findDad(a);
    sick[a].insert(b);
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        out[i] = false;
        maybe.insert(i);
        dad[i] = mn[i] = mx[i] = i;
    }
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int a, b, x;
            cin >> a >> b >> x;
            if (x == 0) {
                updNotSick(a, b);
            } else {
                updSick(a, b);
            }
        } else {
            int x;
            cin >> x;
            if (out[x]) {
                cout << "NO\n";
            } else {
                bool found = false;

                int l = (x > 1 && out[x - 1] ? findDad(x - 1) : x);
                int r = (x < n && out[x + 1] ? findDad(x + 1) : x);

                if (l != x) {
                    auto it = sick[l].lower_bound(x);
                    if (it != sick[l].end() && *it <= mx[r]) {
                        found = true;
                    }
                }

                {
                    auto it = sick[x].begin();
                    if (it != sick[x].end() && *it <= mx[r]) {
                        found = true;
                    }
                }

                if (found) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            }
        }
    }
    return 0;
}