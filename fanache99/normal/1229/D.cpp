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
const int MAXK = 5;
const int MAXFACTK = 120;

map<vector<int>, int> code;
int compose[MAXFACTK][MAXFACTK];

void precompute(int k) {
    vector<int> p(k);
    iota(p.begin(), p.end(), 0);
    int id = 0;
    do {
        code[p] = id++;
    } while (next_permutation(p.begin(), p.end()));

    iota(p.begin(), p.end(), 0);
    do {
        vector<int> q(k);
        iota(q.begin(), q.end(), 0);
        do {
            vector<int> r(k);
            for (int i = 0; i < k; i++) {
                r[i] = q[p[i]];
            }
            compose[code[p]][code[q]] = code[r];
        } while (next_permutation(q.begin(), q.end()));
    } while (next_permutation(p.begin(), p.end()));
}

int v[1 + MAXN];
int last[MAXFACTK];
bool seen[MAXFACTK];

void DFS(int node, vector<int> &basis, int &reachable) {
    seen[node] = true;
    reachable++;
    for (auto it : basis) {
        if (!seen[compose[node][it]]) {
            DFS(compose[node][it], basis, reachable);
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
    int n, k;
    cin >> n >> k;
    precompute(k);
    long long answer = 0;
    set<pair<int, int> > order;
    for (int i = 1; i <= n; i++) {
        vector<int> p(k);
        for (int j = 0; j < k; j++) {
            cin >> p[j];
            p[j]--;
        }
        v[i] = code[p];
        if (last[v[i]] != 0) {
            order.erase({-last[v[i]], v[i]});
        }
        last[v[i]] = i;
        order.insert({-last[v[i]], v[i]});
        memset(seen, false, sizeof(seen));
        int reachable = 1, lastPos = i;
        seen[0] = true;
        vector<int> basis;
        for (auto it : order) {
            int currPos = -it.first;
            answer += reachable * (lastPos - currPos);
            int x = it.second;
            if (!seen[x]) {
                basis.push_back(x);
                DFS(x, basis, reachable);
            }
            lastPos = currPos;
        }
        answer += reachable * lastPos;
    }
    cout << answer << "\n";
    return 0;
}