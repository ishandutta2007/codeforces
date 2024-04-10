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

const int MAXN = 1000;

struct Point {
    int x;
    int y;
};

Point p[1 + MAXN];
int sol[1 + MAXN];

long long myAbs(long long x) {
    return x < 0 ? -x : x;
}

/*long long ask(int type, int i, int j, int k) {
    if (type == 1) {
        return myAbs(1LL * p[i].x * p[j].y + 1LL * p[j].x * p[k].y + 1LL * p[k].x * p[i].y -
                     1LL * p[i].x * p[k].y - 1LL * p[j].x * p[i].y - 1LL * p[k].x * p[j].y);
    } else {
        return 1LL * (p[j].x - p[i].x) * (p[k].y - p[i].y) - 1LL * (p[k].x - p[i].x) * (p[j].y - p[i].y);
    }
}*/

long long ask(int type, int i, int j, int k) {
    cout << type << " " << i << " " << j << " " << k << "\n";
    cout.flush();
    long long ans;
    cin >> ans;
    return ans;
}

void answer(int n) {
    cout << "0";
    for (int i = 1; i <= n; i++) {
        cout << " " << sol[i];
    }
    cout << "\n";
    cout.flush();
    exit(0);
}

bool cmpSecond(pair<int, long long> a, pair<int, long long> b) {
    return a.second < b.second;
}

vector<int> solve(vector<int> v) {
    if (v.empty()) {
        return {};
    }
    int n = v.size();
    vector<pair<int, long long> > d(n);
    long long best = -1;
    int which = -1;
    for (int i = 0; i < n; i++) {
        d[i] = {v[i], ask(1, 1, 2, v[i])};
        if (d[i].second > best) {
            best = d[i].second;
            which = d[i].first;
        }
    }
    vector<pair<int, long long> > a, b;
    for (int i = 0; i < n; i++) {
        if (d[i].first != which) {
            if (ask(2, 1, which, d[i].first) < 0) {
                a.push_back(d[i]);
            }
            else {
                b.push_back(d[i]);
            }
        }
    }
    sort(a.begin(), a.end(), cmpSecond);
    sort(b.begin(), b.end(), cmpSecond);
    reverse(b.begin(), b.end());
    vector<int> ans;
    for (auto it : a) {
        ans.push_back(it.first);
    }
    ans.push_back(which);
    for (auto it : b) {
        ans.push_back(it.first);
    }
    return ans;
}

void add(int &k, int x) {
    sol[++k] = x;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    /*for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }*/
    vector<int> a, b;
    for (int i = 3; i <= n; i++) {
        if (ask(2, 1, 2, i) < 0) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    a = solve(a);
    b = solve(b);
    int k = 0;
    add(k, 1);
    for (auto it : a) {
        add(k, it);
    }
    add(k, 2);
    for (auto it : b) {
        add(k, it);
    }
    answer(n);
    return 0;
}