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

const int MAXN = 50000;

struct Point {
    int x, y, z;
    int id;

    bool operator < (const Point &other) const {
        if (x == other.x) {
            if (y == other.y) {
                return z < other.z;
            }
            return y < other.y;
        }
        return x < other.x;
    }
};

Point p[1 + MAXN];
map<pair<int, int>, int> line;
map<int, int> plane;
int space;
bool out[1 + MAXN];
int st[1 + MAXN];

void print(int i, int j) {
    cout << p[i].id << " " << p[j].id << "\n";
    out[i] = out[j] = true;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1);
    int top = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            top++;
            st[top] = i;
            while (top >= 2 && p[st[top]].x == p[st[top - 1]].x && p[st[top]].y == p[st[top - 1]].y) {
                print(st[top], st[top - 1]);
                top -= 2;
            }
        }
    }
    top = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            top++;
            st[top] = i;
            while (top >= 2 && p[st[top]].x == p[st[top - 1]].x) {
                print(st[top], st[top - 1]);
                top -= 2;
            }
        }
    }
    top = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            top++;
            st[top] = i;
            while (top >= 2) {
                print(st[top], st[top - 1]);
                top -= 2;
            }
        }
    }
    //timeDuration();
    return 0;
}