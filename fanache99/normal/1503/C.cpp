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

const int MAXN = 100000;
const long long INF = 1000000000000000000LL;

struct City {
    int a;
    int c;

    bool operator < (const City &other) const {
        return a < other.a;
    }
};

City v[1 + MAXN];
long long dp[1 + MAXN];
vector<int> out[1 + MAXN + 1];
set<pair<long long, int> > active;

void add(int id, int n) {
    active.insert(make_pair(dp[id], id));
    int left = id + 1, right = n, where = n + 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (v[middle].a - v[id].a > v[id].c) {
            where = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    out[where].push_back(id);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].a >> v[i].c;
        sum += v[i].c;
    }
    sort(v + 1, v + n + 1);
    active.insert(make_pair(INF, 0));
    long long best = INF;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        add(i - 1, n);
        for (auto j : out[i]) {
            active.erase(make_pair(dp[j], j));
            best = min(best, dp[j] - v[j].a - v[j].c);
        }
        dp[i] = min(v[i].a + best, (*active.begin()).first);
    }
    cout << sum + dp[n] << "\n";
    //timeDuration();
    return 0;
}