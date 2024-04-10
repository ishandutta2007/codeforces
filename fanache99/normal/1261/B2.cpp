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

const int MAXN = 200000;
const int MAXLOG = 20;

int val[1 + MAXN];
int v[1 + MAXN];

void normalize(int n, int &m) {
    map<int, int> code;
    for (int i = 1; i <= n; i++) {
        code[v[i]] = 1;
    }
    for (auto &it : code) {
        it.second = ++m;
        val[it.second] = it.first;
    }
    for (int i = 1; i <= n; i++) {
        v[i] = code[v[i]];
    }
}

int fenwick[1 + MAXN], answer[1 + MAXN];
vector<pair<int, int> > queries[1 + MAXN];
pair<int, int> vn[1 + MAXN];

void update(int x, int add, int n) {
    for (; x <= n; x += (x & -x)) {
        fenwick[x] += add;
    }
}

int getPos(int sum, int n) {
    int answer = 0;
    for (int step = MAXLOG; step >= 0; step--) {
        if (answer + (1 << step) <= n && fenwick[answer + (1 << step)] <= sum) {
            sum -= fenwick[answer + (1 << step)];
            answer += (1 << step);
        }
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int m = 0;
    normalize(n, m);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int k, p;
        cin >> k >> p;
        queries[k].push_back({p, i});
    }
    for (int i = 1; i <= n; i++) {
        update(i, 1, n);
        vn[i] = {v[i], -i};
    }
    sort(vn + 1, vn + n + 1);
    for (int i = 1; i <= n; i++) {
        int k = n - i + 1;
        for (auto it : queries[k]) {
            int p = it.first, id = it.second;
            answer[id] = getPos(p - 1, n) + 1;
        }
        update(-vn[i].second, -1, n);
    }
    for (int i = 1; i <= q; i++) {
        cout << val[v[answer[i]]] << "\n";
    }
    //timeDuration();
    return 0;
}