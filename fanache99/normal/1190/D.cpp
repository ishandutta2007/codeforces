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

const int MAXN = 200000;

int x[1 + MAXN], y[1 + MAXN];

void normalize(int v[], int n, int &id) {
    map<int, int> code;
    for (int i = 1; i <= n; i++) {
        code[v[i]] = true;
    }
    id = 0;
    for (auto &it : code) {
        id++;
        it.second = id;
    }
    for (int i = 1; i <= n; i++) {
        v[i] = code[v[i]];
    }
}

pair<int, int> v[1 + MAXN];

int fenwick[1 + MAXN];

void update(int x, int n) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x]++;
    }
}

int query(int x) {
    int answer = 0;
    for (; x > 0; x -= (x & -x)) {
        answer += fenwick[x];
    }
    return answer;
}

bool seen[1 + MAXN];

void subtract(long long &answer, int a, int b) {
    int x = query(b - 1) - query(a);
    answer -= 1LL * x * (x + 1) / 2;
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
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    int xMax, yMax;
    normalize(x, n, xMax);
    normalize(y, n, yMax);
    for (int i = 1; i <= n; i++) {
        v[i] = make_pair(-y[i], x[i]);
    }
    sort(v + 1, v + n + 1);
    long long answer = 0;
    for (int i = 1, j, total = 0; i <= n; i = j) {
        j = i;
        while (j <= n && v[j].first == v[i].first) {
            if (!seen[v[j].second]) {
                seen[v[j].second] = true;
                update(v[j].second, n);
                total++;
            }
            j++;
        }
        answer += 1LL * total * (total + 1) / 2;
        subtract(answer, 0, v[i].second);
        for (int k = i + 1; k < j; k++) {
            subtract(answer, v[k - 1].second, v[k].second);
        }
        subtract(answer, v[j - 1].second, xMax + 1);
    }
    cout << answer << "\n";
    return 0;
}