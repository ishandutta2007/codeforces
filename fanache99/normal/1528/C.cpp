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

const int MAXN = 300000;

vector<int> g1[1 + MAXN], g2[1 + MAXN];
pair<int, int> range[1 + MAXN];
int id;

void DFS2(int node, int father) {
    range[node].first = ++id;
    for (auto son : g2[node]) {
        if (son != father) {
            DFS2(son, node);
        }
    }
    range[node].second = ++id;
}

int best;
set<pair<int, int> > active;

void DFS1(int node, int father) {
    bool in = false;
    pair<int, int> before = {0, 0};
    auto it = active.lower_bound(range[node]);
    if (it == active.end() || (*it).first > range[node].second) {
        in = true;
        if (it != active.begin() && (*prev(it)).second > range[node].second) {
            before = *prev(it);
            active.erase(before);
        }
        active.insert(range[node]);
    }
    best = max(best, (int) active.size());
    for (auto son : g1[node]) {
        if (son != father) {
            DFS1(son, node);
        }
    }
    if (in) {
        active.erase(range[node]);
        if (before != make_pair(0, 0)) {
            active.insert(before);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            g1[p].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            g2[p].push_back(i);
        }
        id = 0;
        DFS2(1, 0);
        best = 0;
        active.clear();
        DFS1(1, 0);
        cout << best << "\n";
        for (int i = 1; i <= n; i++) {
            g1[i].clear();
            g2[i].clear();
        }
    }
    return 0;
}