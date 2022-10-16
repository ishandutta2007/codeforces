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

const int MAXN = 100000;

int cost[1 + 2 * MAXN];
int dad[1 + 2 * MAXN], h[1 + 2 * MAXN];

struct Edge {
    int a;
    int b;
    int c;

    bool operator < (const Edge &other) const {
        return c > other.c;
    }
};

vector<Edge> edges;

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        h[i] = 1;
    }
}

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

void join(int a, int b) {
    if (h[a] > h[b]) {
        swap(a, b);
    }
    dad[a] = b;
    if (h[a] == h[b]) {
        h[b]++;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m + n; i++) {
        cin >> cost[i];
    }
    long long total = 0;
    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            int x;
            cin >> x;
            x += m;
            int c = cost[i] + cost[x];
            total += c;
            edges.push_back({i, x, c});
        }
    }
    sort(edges.begin(), edges.end());
    initialize(n + m);
    long long answer = 0;
    for (auto it : edges) {
        int a = findDad(it.a), b = findDad(it.b);
        if (a != b) {
            answer += it.c;
            join(a, b);
        }
    }
    cout << total - answer << "\n";
    return 0;
}