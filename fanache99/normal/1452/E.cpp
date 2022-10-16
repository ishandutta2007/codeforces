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
#include <unordered_set>

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

int l[1 + MAXN], r[1 + MAXN], delta[1 + MAXN + 1];

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }
    int answer = 0;
    for (int r1 = k; r1 <= n; r1++) {
        int l1 = r1 - k + 1, sum1 = 0;
        for (int i = 0; i <= n + 1; i++) {
            delta[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            if (r[i] <= r1 || l[i] <= l1) {
                sum1 += max(0, min(r1, r[i]) - max(l1, l[i]) + 1);
            } else if (l[i] > r1) {
                delta[l[i]]++;
                delta[min(n + 1, r[i] + 1)]--;
                delta[min(n + 1, l[i] + k)]--;
                delta[min(n + 1, r[i] + k + 1)]++;
            } else {
                int x = r1 - l[i] + 1;
                sum1 += x;
                delta[r1 + 1]++;
                delta[min(n + 1, r[i] + 1)]--;
                delta[min(n + 1, l[i] + k)]--;
                delta[min(n + 1, r[i] - x + 2 + k - 1)]++;
            }
        }
        int current = 0, add = 0;
        for (int r2 = r1; r2 <= n; r2++) {
            add += delta[r2];
            current += add;
            answer = max(answer, sum1 + current);
        }
    }
    cout << answer << "\n";
    return 0;
}