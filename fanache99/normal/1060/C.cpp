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

const int MAXN = 2000;
const int INF = 1000000000;
int a[1 + MAXN], b[1 + MAXN];
int aSum[1 + MAXN], bSum[1 + MAXN];
int aBest[1 + MAXN], bBest[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        aSum[i] = a[i] + aSum[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        bSum[i] = b[i] + bSum[i - 1];
    }
    int limit, answer = 0;
    cin >> limit;
    for (int l = 1; l <= n; l++) {
        aBest[l] = INF;
        for (int i = 1; i + l - 1 <= n; i++) {
            aBest[l] = min(aBest[l], aSum[i + l - 1] - aSum[i - 1]);
        }
    }
    for (int l = 1; l <= m; l++) {
        bBest[l] = INF;
        for (int i = 1; i + l - 1 <= m; i++) {
            bBest[l] = min(bBest[l], bSum[i + l - 1] - bSum[i - 1]);
        }
    }
    for (int la = 1; la <= n; la++) {
        for (int lb = 1; lb <= m; lb++) {
            if (1LL * aBest[la] * bBest[lb] <= limit) {
                answer = max(answer, la * lb);
            }
        }
    }
    cout << answer << "\n";
    return 0;
}