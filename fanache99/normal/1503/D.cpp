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

int v[1 + MAXN + 1], c[1 + MAXN];
int sum[2][1 + MAXN], sumInc[1 + MAXN];
int small[1 + MAXN + 1], big[1 + MAXN + 1];
int p[1 + MAXN], st[1 + MAXN];
bool out[1 + MAXN];

bool isDec(int a, int b) {
    if (a >= b) {
        return true;
    }
    return (sumInc[b] - sumInc[a]) == 0;
}

int getSum(int a, int b, int x) {
    return sum[x][b] - sum[x][a - 1];
}

int solve(int n) {
    int answer = 0, i = 1, smallest = n + 1;
    while (i <= n) {
        smallest = v[i];
        vector<int> a, b;
        a.push_back(i);
        while (n - smallest + 1 != i) {
            i++;
            smallest = min(smallest, v[i]);
            if (v[i] < v[a.back()]) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        int c1 = 0, c2 = 0;
        for (auto it : a) {
            c1 += c[it] == 0;
            c2 += c[it] == 1;
        }
        for (auto it : b) {
            c1 += c[it] == 1;
            c2 += c[it] == 0;
        }
        answer += min(c1, c2);
        i++;
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if ((a <= n && b <= n) || (a > n && b > n)) {
            cout << "-1\n";
            return 0;
        }
        if (a < b) {
            v[a] = b - n;
            c[a] = 0;
        } else {
            v[b] = a - n;
            c[b] = 1;
        }
    }
    small[0] = n + 1;
    for (int i = 1; i <= n; i++) {
        p[v[i]] = i;
        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        sum[c[i]][i]++;
        small[i] = min(small[i - 1], v[i]);
    }
    big[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        big[i] = max(big[i + 1], v[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] > small[i - 1] && v[i] < big[i + 1]) {
            cout << "-1\n";
            return 0;
        }
    }
    int answer = solve(n);
    cout << answer << "\n";
    //timeDuration();
    return 0;
}