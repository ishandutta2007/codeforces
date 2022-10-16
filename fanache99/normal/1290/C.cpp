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

const int MAXN = 300000;

char s[1 + MAXN];
vector<int> v[1 + MAXN];
vector<int> nodes[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN];
int howMany[1 + MAXN][2];
int dad[1 + MAXN], type[1 + MAXN], tempType[1 + MAXN];

void initialize(int k) {
    for (int i = 1; i <= k; i++) {
        type[i] = -1;
        dad[i] = i;
        tempType[i] = 0;
        howMany[i][0] = 1;
        howMany[i][1] = 0;
        nodes[i].push_back(i);
    }
}

void setType(int node, int t, int &answer) {
    type[node] = t;
    answer += t;
    for (auto it : g[node]) {
        if (type[it.first] == -1) {
            setType(it.first, t ^ it.second, answer);
        }
    }
}

void makeType(int node, int t, int &answer) {
    if (type[node] != -1) {
        assert(type[node] == t);
        return;
    }
    answer -= min(howMany[dad[node]][0], howMany[dad[node]][1]);
    setType(node, t, answer);
}

void addEdge(int a, int b, int t, int &answer) {
    if (dad[a] == dad[b]) {
        return;
    }
    if (nodes[dad[a]].size() > nodes[dad[b]].size()) {
        swap(a, b);
    }
    g[a].push_back({b, t});
    g[b].push_back({a, t});
    if (type[a] == -1) {
        answer -= min(howMany[dad[a]][0], howMany[dad[a]][1]);
    }
    if (type[b] == -1) {
        answer -= min(howMany[dad[b]][0], howMany[dad[b]][1]);
    }
    int x = tempType[a] ^ tempType[b] ^ t;
    for (auto it : nodes[dad[a]]) {
        dad[it] = dad[b];
        tempType[it] ^= x;
        nodes[dad[b]].push_back(it);
        howMany[dad[b]][tempType[it]]++;
    }
    if (type[a] == -1 && type[b] == -1) {
        answer += min(howMany[dad[b]][0], howMany[dad[b]][1]);
    } else if (type[a] == -1) {
        setType(a, type[b] ^ t, answer);
    } else if (type[b] == -1) {
        setType(b, type[a] ^ t, answer);
    } else {
        assert((type[a] ^ type[b]) == t);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k >> (s + 1);
    for (int i = 1; i <= k; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    initialize(k);
    for (int i = 1, answer = 0; i <= n; cout << answer << "\n", i++) {
        if (v[i].empty()) {
            assert(s[i] == '1');
            continue;
        }
        if (v[i].size() == 1) {
            makeType(v[i][0], 1 - (s[i] - '0'), answer);
        } else {
            addEdge(v[i][0], v[i][1], 1 - (s[i] - '0'), answer);
        }
    }
    return 0;
}