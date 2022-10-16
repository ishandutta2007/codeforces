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

const int MAXSOL = 200;

int inv(int op) {
    if (op == 3) {
        return 3;
    } else {
        return 3 - op;
    }
}

int raiseToPower(int base, int mod, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % mod;
        }
        base = 1LL * base * base % mod;
        power >>= 1;
    }
    return answer;
}

int apply(int x, int p, int op) {
    if (op == 1) {
        return x == p - 1 ? 0 : x + 1;
    } else if (op == 2) {
        return x == 0 ? p - 1 : x - 1;
    } else {
        return raiseToPower(x, p, p - 2);
    }
}

void extend(queue<int> &q, map<int, int> &d, map<int, int> &o, int &m, int p) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= 3; i++) {
        int y = apply(x, p, i);
        if (d.find(y) == d.end()) {
            d[y] = i;
            q.push(y);
            if (o.find(y) != o.end()) {
                m = y;
                return;
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int u, v, p;
    cin >> u >> v >> p;
    if (u == v) {
        cout << "0\n";
    } else {
        map<int, int> du, dv;
        du[u] = 0;
        dv[v] = 0;
        queue<int> qu, qv;
        qu.push(u);
        qv.push(v);
        int m = -1;
        while (1) {
            extend(qu, du, dv, m, p);
            extend(qv, dv, du, m, p);
            if (m != -1) {
                break;
            }
        }
        vector<int> sol;
        for (int x = m; x != u; x = apply(x, p, inv(du[x]))) {
            sol.push_back(du[x]);
        }
        reverse(sol.begin(), sol.end());
        for (int x = m; x != v; x = apply(x, p, inv(dv[x]))) {
            sol.push_back(inv(dv[x]));
        }
        assert(sol.size() <= MAXSOL);
        cout << sol.size() << "\n";
        for (auto it : sol) {
            cout << it << " ";
            u = apply(u, p, it);
        }
        assert(u == v);
    }
    //timeDuration();
    return 0;
}