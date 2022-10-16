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

const int MAXM = 100000;
const int DIV = 100000;

bool ok[1 + MAXM];
int answer[1 + MAXM];
vector<int> g[1 + MAXM];
int best[1 + MAXM];

long long go(long long k, int type, long long x, long long m) {
    if (type == 1) {
        return min(m + 1, (k * DIV + x - 1) / DIV + 1);
    } else {
        if (k == 0) {
            return 0;
        }
        return min(m + 1, (k * x - 1) / DIV + 1);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        answer[i] = -1;
    }
    ok[0] = true;
    for (int i = 1; i <= n; i++) {
        int type, y;
        long long x;
        cin >> type >> x >> y;
        for (int j = 0; j <= m; j++) {
            int k = go(j, type, x, m);
            assert(k > j || k == 0);
            if (k <= m && k > j) {
                g[k].push_back(j);
            }
            best[j] = 0;
            for (auto j0 : g[j]) {
                best[j] = max(best[j], best[j0] - 1);
            }
            if (!ok[j]) {
                if (best[j] > 0) {
                    ok[j] = true;
                    answer[j] = i;
                }
            } else {
                best[j] = y + 1;
            }
        }
        for (int j = 0; j <= m; j++) {
            g[j].clear();
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << answer[i] << " ";
    }
    //timeDuration();
    return 0;
}