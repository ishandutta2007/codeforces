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

const int MAXN = 1000000;
const int MAXW = 1000000;

int v[1 + MAXN + 1];
long long sum[1 + MAXW + 1];

void add(int a, int b, long long c) {
    sum[a] += c;
    sum[b + 1] -= c;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            cin >> v[j];
        }
        v[0] = v[l + 1] = 0;
        if (2 * l + 1 > w) {
            deque<int> dq;
            dq.push_back(0);
            for (int j = 1; j <= w; j++) {
                if (j <= l + 1) {
                    while (!dq.empty() && v[dq.back()] <= v[j]) {
                        dq.pop_back();
                    }
                    dq.push_back(j);
                }
                while (!dq.empty() && dq.front() < l + j - w) {
                    dq.pop_front();
                }
                assert(!dq.empty());
                add(j, j, v[dq.front()]);
            }
        } else {
            int best = 0;
            for (int j = 1; j <= l; j++) {
                best = max(best, v[j]);
                add(j, j, best);
            }
            best = 0;
            for (int j = w; j >= w - l + 1; j--) {
                best = max(best, v[l - (w - j)]);
                add(j, j, best);
            }
            add(l + 1, w - l, best);
        }
    }
    for (int j = 1; j <= w; j++) {
        sum[j] += sum[j - 1];
        cout << sum[j] << " ";
    }
    //timeDuration();
    return 0;
}