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
#include <unordered_set>

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

const int MAXN = 200000;
const int SQRT = 50;

vector<int> v[1 + MAXN];

bool good[1 + MAXN];

void search(int n) {
    vector<pair<pair<int, int>, int> > pairs;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() <= SQRT) {
            sort(v[i].begin(), v[i].end());
            for (int i1 = 0; i1 < v[i].size(); i1++) {
                for (int i2 = i1 + 1; i2 < v[i].size(); i2++) {
                    pairs.push_back(make_pair(make_pair(v[i][i1], v[i][i2]), i));
                }
            }
        } else {
            for (auto it : v[i]) {
                good[it] = true;
            }
            for (int j = 1; j <= n; j++) {
                if (j < i || v[j].size() <= SQRT) {
                    int matches = 0;
                    for (auto jt : v[j]) {
                        if (good[jt]) {
                            matches++;
                            if (matches == 2) {
                                cout << i << " " << j << "\n";
                                for (auto it : v[i]) {
                                    good[it] = false;
                                }
                                return;
                            }
                        }
                    }
                }
            }
            for (auto it : v[i]) {
                good[it] = false;
            }
        }
    }
    sort(pairs.begin(), pairs.end());
    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i].first == pairs[i - 1].first && pairs[i].second != pairs[i - 1].second) {
            cout << pairs[i - 1].second << " " << pairs[i].second << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        map<int, bool> seen;
        map<int, int> code;
        for (int i = 1; i <= n; i++) {
            int sz;
            cin >> sz;
            for (int j = 1; j <= sz; j++) {
                int x;
                cin >> x;
                v[i].push_back(x);
                seen[x] = true;
            }
        }
        int id = 0;
        for (auto it : seen) {
            id++;
            code[it.first] = id;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                v[i][j] = code[v[i][j]];
            }
        }
        search(n);
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
    }
    return 0;
}