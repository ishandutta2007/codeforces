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

clock_t timeStart, timecinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timecinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timecinish - timeStart) / double(CLOCKS_PER_SEC);
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
    inline InputReader &operator >>(long long &n) {
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

const int MAXN = 200000;
const int MOD = 1000000007;

int low[1 + MAXN];

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (low[i] == 0) {
            low[i] = i;
            for (int j = 2 * i; j <= MAXN; j += i) {
                if (low[j] == 0) {
                    low[j] = i;
                }
            }
        }
    }
}

vector<pair<int, int> > decompose(int x) {
    vector<pair<int, int> > d;
    while (x != 1) {
        int y = low[x];
        d.push_back({y, 0});
        while (x % y == 0) {
            x /= y;
            d.back().second++;
        }
    }
    return d;
}

set<pair<int, int> > ds[1 + MAXN];
map<pair<int, int>, int> ps;

int getPower(int d, int n) {
    return ds[d].size() < n ? 0 : ds[d].begin()->first;
}

void add(int d, int p, int i, int n, int &answer) {
    int before = getPower(d, n);
    int p0 = ps.find({i, d}) == ps.end() ? 0 : ps[{i, d}];
    if (p0 != 0) {
        ds[d].erase({p0, i});
    }
    p0 += p;
    ds[d].insert({p0, i});
    ps[{i, d}] = p0;
    int now = getPower(d, n);
    for (int j = before + 1; j <= now; j++) {
        answer = 1LL * answer * d % MOD;
    }
}

void multiply(int i, int x, int n, int &answer) {
    vector<pair<int, int> > d = decompose(x);
    for (auto it : d) {
        add(it.first, it.second, i, n, answer);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int n, q;
    cin >> n >> q;
    int answer = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        multiply(i, x, n, answer);
    }
    for (int i = 1; i <= q; i++) {
        int p, x;
        cin >> p >> x;
        multiply(p, x, n, answer);
        cout << answer << "\n";
    }
    //timeDuration();
    return 0;
}