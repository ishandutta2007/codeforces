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

const int MAXN = 1000;

vector<int> g[1 + MAXN];
int n, queries = 0;

int ask(int a, int b) {
    assert(a != b);
    assert(1 <= a && a <= n && 1 <= b && b <= n);
    queries++;
    assert(queries <= n / 2);
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void answer(int r) {
    cout << "! " << r << "\n";
    cout.flush();
    exit(0);
}

bool out[1 + MAXN];
queue<int> nodes;
int degree[1 + MAXN];

void remove(int node) {
    for (auto it : g[node]) {
        if (!out[it]) {
            degree[it]--;
            if (degree[it] == 1) {
                out[it] = true;
                nodes.push(it);
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        degree[i] = g[i].size();
        if (degree[i] == 1) {
            nodes.push(i);
            out[i] = true;
        }
    }
    while (!nodes.empty()) {
        int a = nodes.front();
        nodes.pop();
        if (nodes.empty()) {
            answer(a);
        } else {
            int b = nodes.front();
            nodes.pop();
            int c = ask(a, b);
            if (c == a || c == b) {
                answer(c);
            } else {
                remove(a);
                remove(b);
            }
        }
    }
    //timeDuration();
    return 0;
}