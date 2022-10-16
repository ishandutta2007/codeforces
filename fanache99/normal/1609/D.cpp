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

const int MAXN = 1000;

int dad[1 + MAXN], weight[1 + MAXN];

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

void join(int a, int b) {
    a = findDad(a), b = findDad(b);
    if (a == b) {
        return;
    }
    if (rand() % 2) {
        dad[a] = b;
        weight[b] += weight[a];
    } else {
        dad[b] = a;
        weight[a] += weight[b];
    }
}

int solve(int n, int e) {
    vector<int> w;
    for (int i = 1; i <= n; i++) {
        if (dad[i] == i) {
            w.push_back(weight[i]);
        }
    }
    sort(w.begin(), w.end());
    assert(w.size() + e >= n);
    e -= (n - w.size());
    int ans = w.back() - 1;
    w.pop_back();
    while (!w.empty() && e > 0) {
        e--;
        ans += w.back();
        w.pop_back();
    }
    return ans;
}

int main() {
    timeBegin();
   // ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        weight[i] = 1;
    }
    for (int i = 1; i <= d; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
        cout << solve(n, i) << "\n";
    }
    return 0;
}