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

const int BASE = 27;
const int MAXVAL = 531441;
const int MAXN = 100000;

string p[1 + MAXN];
int c[1 + MAXN];

int code(string s, int k) {
    int answer = 0;
    for (int i = k - 1; i >= 0; i--) {
        char ch = s[i];
        answer = answer * BASE + (ch == '_' ? 26 : ch - 'a');
    }
    return answer;
}

bool matches(string a, string b, int k) {
    for (int i = 0; i < k; i++) {
        if (a[i] != '_' && b[i] != '_' && a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int id[MAXVAL];
vector<int> g[1 + MAXN];
int degree[1 + MAXN];

void addEdges(string s, int x, int k) {
    for (int i = 0; i < (1 << k); i++) {
        string temp = "";
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                temp.push_back('_');
            } else {
                temp.push_back(s[j]);
            }
        }
        int y = code(temp, k);
        if (x != y && id[y]) {
            g[id[x]].push_back(id[y]);
            degree[id[y]]++;
        }
    }
}

int q[1 + MAXN];

bool sortOp(int n) {
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        if (!degree[i]) {
            r++;
            q[r] = i;
        }
    }
    while (l <= r) {
        int node = q[l];
        l++;
        for (auto it : g[node]) {
            degree[it]--;
            if (!degree[it]) {
                r++;
                q[r] = it;
            }
        }
    }
    return r == n;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        c[i] = code(p[i], k);
        id[c[i]] = i;
    }
    bool bad = false;
    for (int i = 1; i <= m; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (!matches(s, p[x], k)) {
            bad = true;
        }
        addEdges(s, c[x], k);
    }
    if (bad) {
        cout << "NO\n";
    } else {
        if (!sortOp(n)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << q[i] << " ";
            }
        }
    }
    //timeDuration();
    return 0;
}