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

const int MAXN = 3000000;

int v[1 + MAXN], st[1 + MAXN], toLeft[1 + MAXN], toRight[1 + MAXN], first[1 + MAXN], second[1 + MAXN], add[1 + MAXN + 1];
vector<int> in[1 + MAXN + 1], out[1 + MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, top = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            add[i] = 0;
            in[i].clear();
            out[i].clear();
            first[i] = second[i] = 0;
            cin >> v[i];
            while (top > 0 && v[st[top]] > v[i]) {
                toRight[st[top]] = i;
                top--;
            }
            toLeft[i] = st[top];
            top++;
            st[top] = i;
        }
        while (top > 0) {
            toRight[st[top]] = n + 1;
            top--;
        }
        for (int i = 1; i <= n; i++) {
            int l = toRight[i] - toLeft[i];
            if (l > first[v[i]]) {
                second[v[i]] = first[v[i]];
                first[v[i]] = l;
            } else if (l > second[v[i]]) {
                second[v[i]] = l;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (first[i] != 0) {
                if (second[i] == 0) {
                    second[i] = 1;
                }
                in[second[i]].push_back(i);
                out[first[i]].push_back(i);
            }
        }
        set<int> active;
        for (int i = 1; i <= n; i++) {
            for (auto it : in[i]) {
                active.insert(it);
            }
            for (auto it : out[i]) {
                active.erase(it);
            }
            if (active.size() == n - i + 1 && *active.rbegin() == n - i + 1) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}