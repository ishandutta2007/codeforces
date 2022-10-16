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

const int MAXN = 100000;
const long long LIMIT = 2250000000000;

long long x[1 + MAXN], y[1 + MAXN];
int sign[1 + MAXN], p[1 + MAXN];

long long absLl(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }
    while (true) {
        long long sx = 0, sy = 0;
        for (int i = 1; i <= n; i++) {
            long long sx1 = sx + x[p[i]], sy1 = sy + y[p[i]];
            long long sx2 = sx - x[p[i]], sy2 = sy - y[p[i]];
            if (absLl(sx1) < absLl(sx2) && absLl(sy1) < absLl(sy2)) {
                sx = sx1;
                sy = sy1;
                sign[p[i]] = 1;
            } else if (absLl(sx2) < absLl(sx1) && absLl(sy2) < absLl(sy1)) {
                sx = sx2;
                sy = sy2;
                sign[p[i]] = -1;
            } else if (rand() % 2 == 0) {
                sx = sx1;
                sy = sy1;
                sign[p[i]] = 1;
            } else {
                sx = sx2;
                sy = sy2;
                sign[p[i]] = -1;
            }
            //assert(sx * sx + sy * sy <= LIMIT);
        }
        if(sx * sx + sy * sy <= LIMIT) {
            for (int i = 1; i <= n; i++) {
                cout << sign[i] << " ";
            }
            return 0;
        }
    }

    //timeDuration();
    return 0;
}