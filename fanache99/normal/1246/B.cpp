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

const int MAXLOG = 40;

bool can(long long n, long long b, long long p) {
    n -= b * p;
    if (n <= 0) {
        return false;
    }
    if (b >= __builtin_popcountll(n) && b <= n) {
        return true;
    } else {
        return false;
    }
}

const int MAXN = 100000;

int v[1 + MAXN];
map<vector<pair<int, int> >, int> seen;

vector<pair<int, int> > decompose(int n, int k) {
    vector<pair<int, int> > ans;
    for (int d = 2; d * d <= n; d++) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        if (p % k != 0) {
            ans.push_back({d, p % k});
        }
    }
    if (n != 1) {
        ans.push_back({n, 1});
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        vector<pair<int, int> > d = decompose(v[i], k);
        vector<pair<int, int> > e(d.size());
        for (int i = 0; i < d.size(); i++) {
            assert(d[i].second != 0);
            e[i] = {d[i].first, k - d[i].second};
        }
        answer += seen[e];
        seen[d]++;
    }
    cout << answer << "\n";
    return 0;
}