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

const int MAXN = 100000;

pair<int, int> d[1 + MAXN];
int v[1 + MAXN + 1];
vector<pair<int, int> > l[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].first;
        d[i].second = i;
    }
    sort(d + 1, d + n + 1);
    reverse(d + 1, d + n + 1);
    v[1] = 2 * d[1].second - 1;
    v[d[1].first + 1] = 2 * d[1].second;
    int p = 2;
    for (int i = d[1].first; i > 1; i--, p++) {
        v[i] = 2 * d[p].second - 1;
        if (i - d[p].first >= 1) {
            l[i - d[p].first + 1].push_back(make_pair(1, 2 * d[p].second));
        } else {
            l[1].push_back(make_pair(d[p].first - i + 1, 2 * d[p].second));
        }
    }
    vector<pair<int, int> > edges;
    for (; p <= n; p++) {
        l[1].push_back(make_pair(1, 2 * d[p].second - 1));
        if (d[p].first == 1) {
            edges.push_back(make_pair(2 * d[p].second - 1, 2 * d[p].second));
        } else {
            l[d[p].first - 1].push_back(make_pair(1, 2 * d[p].second));
        }
    }
    for (int i = 1; i <= d[1].first; i++) {
        edges.push_back(make_pair(v[i], v[i + 1]));
    }
    for (int i = 1; i <= d[1].first + 1; i++) {
        int dad, depth = 0, last = v[i];
        sort(l[i].begin(), l[i].end());
        for (auto it : l[i]) {
            if (it.first > depth) {
                depth = it.first;
                dad = last;
            }
            edges.push_back(make_pair(dad, it.second));
            last = it.second;
        }
    }
    assert(edges.size() == 2 * n - 1);
    for (auto it : edges) {
        cout << it.first << " " << it.second << "\n";
    }
    //timeDuration();
    return 0;
}