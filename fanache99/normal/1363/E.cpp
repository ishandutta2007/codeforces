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

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
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

const int MAXN = 200000;
const int INF = 1000000000;

vector<int> g[1 + MAXN];
int v[1 + MAXN], a[1 + MAXN], b[1 + MAXN];
int aHave[2], bHave[2];
long long answer = 0;

int DFS(int node, int father, int best) {
    best = min(best, v[node]);
    int first = 0, second = 0;
    for (auto son : g[node]) {
        if (son != father) {
            int x = DFS(son, node, best);
            if (x > 0) {
                first += x;
            }
            else {
                second -= x;
            }
        }
    }
    if (a[node] == 0 && b[node] == 1) {
        first++;
    }
    if (a[node] == 1 && b[node] == 0) {
        second++;
    }
    answer += 2LL * best * min(first, second);
    return first - second;
}

int main() {
    timeBegin();
    //InputReader cin("input.in");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> a[i] >> b[i];
        aHave[a[i]]++;
        bHave[b[i]]++;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    if (aHave[0] != bHave[0] || aHave[1] != bHave[1]) {
        cout << "-1\n";
    } else {
        assert(DFS(1, 0, INF) == 0);
        cout << answer << "\n";
    }
    //timeDuration();
    return 0;
}