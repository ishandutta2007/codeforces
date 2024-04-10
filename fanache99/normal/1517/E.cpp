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

const int MAXN = 200000;
const int MOD = 998244353;

int v[1 + MAXN];
long long sum[1 + MAXN];
long long sum2[1 + MAXN];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

long long getSum(int a, int b) {
    return sum[b] - sum[a - 1];
}

long long getSum2(int a, int b) {
    assert((b - a + 1) % 2 == 0);
    return sum2[b] - sum2[a - 1];
}

int startWithP(int n) {
    int answer = 0;

    // PP...PC...C
    for (int i = 2; i <= n; i++) {
        addTo(answer,  (getSum(1, i) > getSum(i + 1, n)));
    }

    //PCC...CC
    addTo(answer,  (getSum(1, 1) > getSum(2, n)));

    //PCC..CCPP...P
    for (int i = 3; i + 1 <= n; i++) {
        addTo(answer,  (getSum(1, 1) + getSum(i + 1, n) > getSum(2, i)));
    }

    //PCC...CCCCPPPP...PPC
    for (int i = 3; i + 3 <= n; i++) {
        addTo(answer,  (getSum(1, 1) + getSum(i + 1, n - 1) > getSum(2, i) + getSum(n, n)));
    }

    //PCCCC...CCCPCPC....PCPCPPPPP..PP
    for (int i = 3; i + 2 <= n; i++) {
        long long delta = getSum(1, 1) - getSum(2, i);
        int left = 1, right = (n - i) / 2, best = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (delta + getSum2(i + 1, i + 2 * middle) + getSum(i + 2 * middle + 1, n) > 0) {
                best = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        addTo(answer,  best);
    }

    //PCCCC...CCCPCPCPC....PCPCPPPP...PPPC
    for (int i = 3; i + 5 <= n; i++) {
        long long delta = getSum(1, 1) - getSum(2, i) - getSum(n, n);
        int left = 1, right = (n - i - 3) / 2, best = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (delta + getSum2(i + 1, i + 2 * middle) + getSum(i + 2 * middle + 1, n - 1) > 0) {
                best = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        addTo(answer,  best);
    }

    //PCPCPCPC....PPPP
    for (int i = 2; i <= n; i += 2) {
        addTo(answer,  (getSum2(1, i) + getSum(i + 1, n) > 0));
    }

    //PCPCPCPC....PCPCPPPPPC
    for (int i = 2; i + 3 <= n; i += 2) {
        addTo(answer,  (getSum2(1, i) + getSum(i + 1, n - 1) - getSum(n, n) > 0));
    }
    return answer;
}

int startWithC(int n) {
    int answer = 0;

    //CCCC....PPPP
    for (int i = 1; i <= n; i++) {
        addTo(answer, getSum(i + 1, n) - getSum(1, i) > 0);
    }

    //CCCC.....PPPPC
    for (int i = 1; i + 3 <= n; i++) {
        addTo(answer, getSum(i + 1, n - 1) - getSum(1, i) - getSum(n, n) > 0);
    }

    //CCCCC...PCPCPCPC
    for (int i = 1; i + 2 <= n; i++) {
        if ((n - i) % 2 == 0) {
            addTo(answer, getSum2(i + 1, n) - getSum(1, i) > 0);
        }
    }

    //CCCC...PCPCPC...PPPP
    for (int i = 1; i + 3 <= n; i++) {
        long long delta = -getSum(1, i);
        int left = 1, right = (n - i - 1) / 2, best = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (delta + getSum2(i + 1, i + 2 * middle) + getSum(i + 2 * middle + 1, n) > 0) {
                best = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        addTo(answer,  best);
    }

    //CCCCC...PCPCPC...PPPPC
    for (int i = 1; i + 5 <= n; i++) {
        long long delta = -getSum(1, i) - getSum(n, n);
        int left = 1, right = (n - i - 3) / 2, best = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (delta + getSum2(i + 1, i + 2 * middle) + getSum(i + 2 * middle + 1, n - 1) > 0) {
                best = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        addTo(answer,  best);
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum[i] = sum[i - 1] + v[i];
        }
        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << 1 + (v[1] != v[2]) << "\n";
        } else {
            for (int i = 2; i <= n; i++) {
                sum2[i] = sum2[i - 2] + v[i - 1] - v[i];
            }
            int answer = 0;
            addTo(answer, startWithC(n));
            addTo(answer, startWithP(n));
            cout << answer << "\n";
        }
    }
    return 0;
}