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
#include <unordered_set>

using namespace std;

class InputReader {
public:
    InputReader() {}
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
    inline InputReader &operator >>(long long &n) {
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

struct Point {
    int x;
    int y;
};

Point v[1 + MAXN];

long long det(Point a, Point b, Point c) {
    return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y
            - 1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y;
}

pair<long double, long double> intersect(long double x1, long double y1,
                                         long double x2, long double y2,
                                         long double x3, long double y3,
                                         long double x4, long double y4) {
    long double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
                    ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    long double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
                    ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    return make_pair(x, y);
}

long double distance(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    Point s = {v[n].x, v[n].y + h};
    Point p = v[n];
    long double answer = 0.0;
    for (int i = n - 1; i >= 1; i--) {
        if (det(s, p, v[i]) <= 0) {
            if (det(s, p, v[i]) == 0 && det(p, v[i], v[i + 1]) == 0) {
                answer += distance(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
            } else {
                pair<long double, long double> meet = intersect(s.x, s.y, p.x, p.y, v[i].x, v[i].y, v[i + 1].x,
                                                                v[i + 1].y);
                answer += distance(meet.first, meet.second, v[i].x, v[i].y);
            }
            p = v[i];
        }
    }
    cout << fixed << setprecision(12) << answer << "\n";
    return 0;
}