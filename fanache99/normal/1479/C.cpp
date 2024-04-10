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

const int MAXVAL = 1000000;
const int MAXN = 32;

bool seen[1 + MAXVAL];
int n, l, r;
vector<pair<int, int> > g[1 + MAXN];
int total = 0;
map<pair<int, int>, bool> isEdge;

void addEdge(int a, int b, int c) {
    assert(a < b);
    assert(c >= 1 && c <= MAXVAL);
    assert(!isEdge[make_pair(a, b)]);
    g[a].push_back({b, c});
    isEdge[{a, b}] = true;
}

void DFS(int node, int cost) {
    if (node == n) {
        assert(cost >= l && cost <= r);
        if (seen[cost]) {
            assert(0);
        }
        seen[cost] = true;
        total++;
        return;
    }
    for (auto it : g[node]) {
        DFS(it.first, cost + it.second);
    }
}

void print() {
    assert(n <= MAXN);
    DFS(1, 0);
    assert(total == r - l + 1);
    cout << n << " " << isEdge.size() << "\n";
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            cout << i << " " << j.first << " " << j.second << "\n";
        }
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("greutati.out");
    cin >> l >> r;
    cout << "YES\n";
    if (l == r) {
        n = 2;
        addEdge(1, 2, l);
    } else if (l + 1 == r) {
        n = 3;
        addEdge(1, 2, l);
        addEdge(2, 3, 1);
        addEdge(1, 3, l);
    } else {
        int x = r - l;
        int b = 0;
        while (1 << (b + 1) <= x) {
            b++;
        }
        n = b + 3;
        for (int i = 2; i <= n; i++) {
            addEdge(1, i, 1);
        }
        for (int i = 2; i < b + 2; i++) {
            for (int j = i + 1; j <= b + 2; j++) {
                addEdge(i, j, 1 << (i - 2));
            }
        }
        for (int s = 1, i = b; i >= 0; i--) {
            if (x & (1 << i)) {
                addEdge(i + 2, n, s);
                s += 1 << i;
            }
        }
        if (l != 1) {
            n++;
            addEdge(n - 1, n, l - 1);
        }
    }
    print();
    //timeDuration();
    return 0;
}