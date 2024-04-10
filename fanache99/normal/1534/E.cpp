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

const int MAXN = 500;

int n, k;

int ask(vector<int> v) {
    assert(v.size() == k);
    cout << "?";
    for (auto it : v) {
        cout << " " << it;
    }
    cout << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void answer(int x) {
    cout << "! " << x << "\n";
    cout.flush();
    exit(0);
}

pair<int, int> v[1 + MAXN];

bool check(int n, int k, int t) {
    for (int i = 1, sum = 0; i <= n; i++) {
        sum += v[i].first;
        if (sum > (t / k) * min(k, i)) {
            return false;
        }
    }
    return true;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "-1\n";
        cout.flush();
    } else {
        for (int i = 1; i <= n; i++) {
            v[i] = {1, i};
        }
        int sum = n, p = 1;
        while (!check(n, k, sum)) {
            v[p].first += 2;
            p = (p == n ? 1 : p + 1);
            sum += 2;
        }
        int ans = 0;
        for (int step = 1; step <= sum / k; step++) {
            sort(v + 1, v + n + 1);
            vector<int> w;
            for (int i = n - k + 1; i <= n; i++) {
                assert(v[i].first >= 1);
                v[i].first--;
                w.push_back(v[i].second);
            }
            ans ^= ask(w);
        }
        for (int i = 1; i <= n; i++) {
            assert(v[i].first == 0);
        }
        answer(ans);
    }
    return 0;
}