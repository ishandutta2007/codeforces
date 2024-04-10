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

const int MAXN = 10000000;
const int MOD = 1000000007;

vector<pair<int, int> > g[1 + MAXN];
bool seen[1 + MAXN];
int ans[1 + MAXN];

void addPath(int a, int b, int x, int &n) {
    vector<int> d;
    while (x > 0) {
        d.push_back(x % 10);
        x /= 10;
    }
    reverse(d.begin(), d.end());
    int last = a;
    for (int i = 0; i + 1 < d.size(); i++) {
        n++;
        g[last].push_back({n, d[i]});
        last = n;
    }
    g[last].push_back({b, d.back()});
}

struct Elem {
    vector<int> nodes;
    int val;
};

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int init = n;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        addPath(a, b, i, n);
        addPath(b, a, i, n);
    }
    queue<Elem> q;
    q.push({{1}, 0});
    seen[1] = true;
    while (!q.empty()) {
        Elem elem = q.front();
        q.pop();
        for (int d = 0; d < 10; d++) {
            Elem newElem = {{}, (int) ((10LL * elem.val + d) % MOD)};
            for (auto node : elem.nodes) {
                for (auto it : g[node]) {
                    int other = it.first, d0 = it.second;
                    if (d0 != d) {
                        continue;
                    }
                    if (!seen[other]) {
                        seen[other] = true;
                        ans[other] = newElem.val;
                        newElem.nodes.push_back(other);
                    }
                }
            }
            if (!newElem.nodes.empty()) {
                q.push(newElem);
            }
        }
    }
    for (int i = 2; i <= init; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}