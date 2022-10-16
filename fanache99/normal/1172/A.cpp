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

int a[1 + MAXN], b[1 + MAXN];
bool inHand[1 + MAXN];
int pos[1 + MAXN];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        inHand[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    if (inHand[1]) {
        int add = 0;
        for (int i = 2; i <= n; i++) {
            if (!inHand[i]) {
                add = max(add, pos[i] - (i - 1));
            }
        }
        cout << n + add << "\n";
    } else {
        bool canFill = true;
        for (int j = pos[1] + 1; j <= n; j++) {
            if (b[j] != j - pos[1] + 1) {
                canFill = false;
            }
        }
        if (canFill) {
            for (int j = b[n] + 1; j <= n; j++) {
                if (!inHand[j] && pos[j] >= j - (b[n])) {
                    canFill = false;
                }
            }
            if (canFill) {
                cout << pos[1] - 1 << "\n";
                return 0;
            }
        }
        int add = 0;
        for (int i = 2; i <= n; i++) {
            if (!inHand[i] && pos[i] > pos[1]) {
                add = max(add, (pos[i] - pos[1]) - (i - 1));
            }
        }
        cout << pos[1] + n + add << "\n";
    }
    return 0;
}