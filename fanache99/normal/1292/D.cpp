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

const int MAXK = 5000;

vector<int> primes;
bool notPrime[1 + MAXK];

void precompute() {
    for (int i = 2; i <= MAXK; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAXK; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int have[1 + MAXK];

vector<int> factorise(int k) {
    vector<int> ps;
    for (auto p : primes) {
        for (int pow = p; pow <= k; pow *= p) {
            for (int i = 1; i <= k / pow; i++) {
                ps.push_back(p);
            }
        }
    }
    return ps;
}

int myAbs(int x) {
    return x < 0 ? -x : x;
}

int diff(int k, vector<int> &sol) {
    vector<int> ps = factorise(k);
    reverse(ps.begin(), ps.end());
    int i = 0;
    while (i < ps.size() && i < sol.size() && sol[i] == ps[i]) {
        i++;
    }
    return ps.size() + sol.size() - 2 * i;
}

int fr[1 + MAXK];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    precompute();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k == 0) {
            k = 1;
        }
        have[k]++;
    }
    vector<pair<vector<int>, int> > v;
    for (int k = 1; k <= MAXK; k++) {
        if (have[k] > 0) {
            v.push_back({factorise(k), have[k]});
        }
    }
    vector<int> sol;
    while (true) {
        int best = 0, which = -1;
        memset(fr, 0, sizeof(fr));
        for (auto it : v) {
            if (!it.first.empty()) {
                int x = it.first.back();
                fr[x] += it.second;
                if (fr[x] > best) {
                    best = fr[x];
                    which = x;
                }
            }
        }
        if (which == -1 || 2 * best <= n) {
            break;
        }
        sol.push_back(which);
        vector<pair<vector<int>, int> > vNew;
        for (auto it : v) {
            if (!it.first.empty() && it.first.back() == which) {
                vNew.push_back(it);
                vNew.back().first.pop_back();
            }
        }
        v = vNew;
    }
    sort(sol.begin(), sol.end());
    reverse(sol.begin(), sol.end());
    long long answer = 0;
    for (int k = 1; k <= MAXK; k++) {
        if (have[k] > 0) {
            answer += 1LL * have[k] * diff(k, sol);
        }
    }
    cout << answer << "\n";
    return 0;
}