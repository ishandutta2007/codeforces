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

const int MAXN = 200000;
const int MAXVAL = 1000000;

int v[1 + MAXN];
bool prime[1 + MAXVAL];

void sieve() {
    for (int i = 2; i <= MAXVAL; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= MAXVAL; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= MAXVAL; j += i) {
                prime[j] = false;
            }
        }
    }
}

long long solve(vector<int> &w) {
    long long ans = 0;
    for (int i = 0; i < w.size(); i++) {
        if (prime[w[i]]) {
            int a = i, b = i;
            while (a - 1 >= 0 && w[a - 1] == 1) {
                a--;
            }
            while (b + 1 < w.size() && w[b + 1] == 1) {
                b++;
            }
            ans += 1LL * (i - a + 1) * (b - i + 1);
            ans--;
        }
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    sieve();
    int tests;
    cin >> tests;
    while (tests--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int> > buckets(e);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            buckets[i % e].push_back(v[i]);
        }
        long long ans = 0;
        for (auto &bucket : buckets) {
            ans += solve(bucket);
        }
        cout << ans << "\n";
    }
    return 0;
}