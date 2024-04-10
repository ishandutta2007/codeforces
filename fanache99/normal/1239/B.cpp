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

const int MAXN = 300000;

int sgn(char ch) {
    return (ch == '(' ? 1 : -1);
}

int sum[1 + MAXN], cnt[1 + MAXN][3];

int getCnt(int l, int r, int x) {
    assert(x >= 0 && x < 3);
    return cnt[r][x] - cnt[l - 1][x];
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int temp = 0, smallest = 0, offset = 0;
    for (int i = 0; i < n; i++) {
        temp += sgn(s[i]);
        if (temp < smallest) {
            offset = i + 1;
            smallest = temp;
        }
    }
    if (temp != 0) {
        cout << "0\n1 1\n";
        return 0;
    }
    s = s.substr(offset, n - offset) + s.substr(0, offset);
    sum[0] = 0;
    vector<int> v0, v01;
    v0.push_back(0);
    v01.push_back(0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + sgn(s[i - 1]);
        for (int j = 0; j < 3; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        if (sum[i] < 3) {
            cnt[i][sum[i]]++;
        }
        if (sum[i] == 0) {
            v0.push_back(i);
        }
        if (sum[i] <= 1) {
            v01.push_back(i);
        }
    }
    int best = v0.size() - 1;
    int l = 1, r = 1;
    for (int i = 0; i + 1 < v0.size(); i++) {
        int a = v0[i] + 1, b = v0[i + 1];
        int curr = getCnt(a, b - 1, 1);
        if (curr > best) {
            best = curr;
            l = a;
            r = b;
        }
    }
    for (int i = 0; i + 1 < v01.size(); i++) {
        int a = v01[i] + 1, b = v01[i + 1];
        if (a == b) {
            continue;
        }
        int curr = v0.size() - 1 + getCnt(a, b - 1, 2);
        if (curr > best) {
            best = curr;
            l = a;
            r = b;
        }
    }
    cout << best << "\n" << (l - 1 + offset) % n + 1 << " " << (r - 1 + offset) % n + 1 << "\n";
    return 0;
}