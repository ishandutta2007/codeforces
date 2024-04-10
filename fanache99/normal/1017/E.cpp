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

const int MAXN = 100010;

struct Point {
    int x, y;

    bool const operator < (const Point &other) const {
        return (x < other.x || (x == other.x && y < other.y));
    }
};

long long dist(Point a, Point b) {
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

long long det (Point a, Point b, Point c) {
    return 1LL * (a.x - b.x) * (c.x - b.x) + 1LL * (a.y - b.y) * (c.y - b.y);
}

inline long long area (Point a, Point b, Point c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

vector <Point> convexHull (vector <Point> p) {
    int n = p.size(), m = 0;
    if (n < 3) return p;
    vector <Point> hull(n + n);
    sort(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
        while (m > 1 and area(hull[m - 2], hull[m - 1], p[i]) <= 0) --m;
        hull[m++] = p[i];
    }
    for (int i = n - 2, j = m + 1; i >= 0; --i) {
        while (m >= j and area(hull[m - 2], hull[m - 1], p[i]) <= 0) --m;
        hull[m++] = p[i];
    }
    hull.resize(m - 1); return hull;
}

pair<long long, long long> sa[1 + 2 * MAXN], sb[1 + 2 * MAXN];
int pi[1 + 2 * MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    vector<Point> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    a = convexHull(a);
    b = convexHull(b);
    if (a.size() != b.size()) {
        cout << "NO\n";
    } else {
        n = a.size();
        long long aSum = 0, bSum = 0;
        for (int i = 1; i <= n; i++) {
            sa[i] = {dist(a[(i - 1) % n], a[i % n]), det(a[(i - 1) % n], a[i % n], a[(i + 1) % n])};
            aSum += sa[i].first;
            sb[i] = sb[i + n] = {dist(b[(i - 1) % n], b[i % n]), det(b[(i - 1) % n], b[i % n], b[(i + 1) % n])};
            bSum += sb[i].first;
        }
        if (aSum != bSum) {
            cout << "NO\n";
        } else {
            for (int j = 2, i = 0; j <= n; j++) {
                while (i > 0 && sa[i + 1] != sa[j]) {
                    i = pi[i];
                }
                if (sa[i + 1] == sa[j]) {
                    i++;
                }
                pi[j] = i;
            }
            for (int j = 1, i = 0; j <= 2 * n; j++) {
                while (i > 0 && sa[i + 1] != sb[j]) {
                    i = pi[i];
                }
                if (sa[i + 1] == sb[j]) {
                    i++;
                }
                if (i == n) {
                    cout << "YES\n";
                    return 0;
                }
            }
            cout << "NO\n";
        }
    }
    return 0;
}