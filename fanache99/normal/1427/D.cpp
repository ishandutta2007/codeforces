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

const int MAXN = 52;

int v[1 + MAXN], temp[1 + MAXN];

bool sorted(int n) {
    for (int i = 1; i <= n; i++) {
        if (v[i] != i) {
            return false;
        }
    }
    return true;
}

void print(int n) {
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<vector<int> > sol;

void perform(int n, vector<int> d) {
    sol.push_back(d);
    vector<int> sum(d.size());
    sum[0] = 0;
    for (int i = 1; i < d.size(); i++) {
        sum[i] = sum[i - 1] + d[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        temp[i] = v[i];
    }
    for (int i = d.size() - 1, k = 0; i >= 0; i--) {
        for (int j = sum[i] + 1; j <= sum[i] + d[i]; j++) {
            k++;
            v[k] = temp[j];
        }
    }
    //print(n);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    //print(n);
    if (sorted(n)) {
        cout << "0\n";
    } else {
        while (!sorted(n)) {
            int i = 1;
            while (v[i] == i) {
                i++;
            }
            int j = i + 1;
            while (v[j] != v[i] - 1) {
                j++;
            }
            if (i == 1) {
                if (j == n) {
                    int d1 = 1;
                    while (v[d1] + 1 == v[d1 + 1]) {
                        d1++;
                    }
                    vector<int> d = {d1, n - d1};
                    perform(n, d);
                } else {
                    int d2 = 1;
                    while (v[j - d2] + 1 == v[j - d2 + 1]) {
                        d2++;
                    }
                    vector<int> d = {j - d2, d2, n - j};
                    perform(n, d);
                }
            } else {
                if (j == n) {
                    vector<int> d = {i - 1, 1, n - i};
                    perform(n, d);
                } else {
                    int d2 = 1;
                    while (v[i + d2 - 1] + 1 == v[i + d2]) {
                        d2++;
                    }
                    vector<int> d = {i - 1, d2, j - (i + d2 - 1), n - j};
                    perform(n, d);
                }
            }
        }
        assert(sol.size() <= n);
        cout << sol.size() << "\n";
        for (auto d : sol) {
            cout << d.size() << " ";
            for (auto it : d) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}