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

const int MAXN = 2000;

char s[1 + MAXN], t[1 + MAXN];

void check(int n, int k) {
    int p = 0;
    for (int i = 1, s = 0; i <= n; i++) {
        s += (t[i] == '(' ? 1 : -1);
        assert(s >= 0);
        p += (s == 0);
    }
    assert(p == k);
}

void transform(int n, int k) {
    check(n, k);
    vector<pair<int, int> > sol;
    for (int i = n; i >= 1; i--) {
        if (s[i] == t[i]) {
            continue;
        }
        for (int j = i - 1; j >= 1; j--) {
            if (s[j] == t[i]) {
                sol.push_back({j, i});
                reverse(s + j, s + i + 1);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        assert(s[i] == t[i]);
    }
    cout << sol.size() << "\n";
    for (auto it : sol) {
        cout << it.first << " " << it.second << "\n";
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k >> (s + 1);
        int l = n / 2 - k + 1;
        for (int i = 1; i <= l; i++) {
            t[i] = '(';
        }
        for (int i = l + 1; i <= 2 * l; i++) {
            t[i] = ')';
        }
        for (int i = 2 * l + 1; i <= n; i += 2) {
            t[i] = '(';
            t[i + 1] = ')';
        }
        transform(n, k);
    }
    //timeDuration();
    return 0;
}