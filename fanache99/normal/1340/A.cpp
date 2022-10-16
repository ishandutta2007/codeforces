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

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
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

int v[1 + MAXN], where[1 + MAXN];
int dad[1 + MAXN], weight[1 + MAXN];
set<pair<int, int> > active;

void initialize(int n) {
    active.clear();
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        weight[i] = 1;
        active.insert(make_pair(weight[i], i));
    }
}

int findDad(int node) {
    if (node == dad[node])
        return node;
    return dad[node] = findDad(dad[node]);
}

void join(int a, int b) {
    active.erase(active.find(make_pair(weight[a], a)));
    active.erase(active.find(make_pair(weight[b], b)));
    if (rand() % 2) {
        dad[b] = a;
        weight[a] += weight[b];
        active.insert(make_pair(weight[a], a));
    }
    else {
        dad[a] = b;
        weight[b] += weight[a];
        active.insert(make_pair(weight[b], b));
    }
}

void eliminate(int x, int &n) {
    if (x == n) {
        active.erase(active.find(make_pair(weight[findDad(x)], findDad(x))));
        n -= weight[findDad(x)];
    } else
        join(findDad(x), findDad(x + 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            where[v[i]] = i;
        }
        initialize(n);
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (weight[findDad(where[i])] != active.rbegin()->first) {
                bad = true;
                break;
            }
            eliminate(where[i], n);
        }
        if (bad)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}