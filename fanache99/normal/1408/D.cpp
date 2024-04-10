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

const int MAXN = 2000;
const int MAXVAL = 1000000;

struct Point {
    int x;
    int y;
};

Point r[1 + MAXN], s[1 + MAXN];
int limit[1 + MAXVAL + 2];

inline bool compare(const Point &a, const Point &b) {
    return a.y > b.y || (a.y == b.y && a.x > b.x);
}

int distance(int x, int y, int xLimit, int yLimit) {
    return max(0, xLimit - x) + max(0, yLimit - y);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i].x >> r[i].y;
    }
    for (int i = 1; i <= m; i++) {
        cin >> s[i].x >> s[i].y;
    }
    sort(s + 1, s + m + 1, compare);
    for (int i = 1; i <= n; i++) {
        int xLimit = 0, yLimit = MAXVAL + 1;
        for (int j = 1; j <= m && s[j].y >= r[i].y; j++) {
            limit[yLimit] = max(limit[yLimit], max(0, xLimit - r[i].x));
            xLimit = max(xLimit, s[j].x + 1);
            yLimit = s[j].y - r[i].y;
        }
        limit[yLimit] = max(limit[yLimit], max(0, xLimit - r[i].x));
    }
    int answer = 2 * (MAXVAL + 1);
    for (int i = MAXVAL + 1; i >= 0; i--) {
        limit[i] = max(limit[i], limit[i + 1]);
        answer = min(answer, i + limit[i]);
    }
    cout << answer << "\n";
    return 0;
}