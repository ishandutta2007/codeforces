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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100000;

int a[1 + MAXN], b[1 + MAXN], orda[1 + MAXN], ordb[1 + MAXN];
int wa[1 + MAXN], wb[1 + MAXN];
char ok[1 + MAXN + 1];
bool seen[1 + MAXN];
int nodes = 0;

void DFS(int node) {
    seen[node] = true;
    nodes++;
    int i = wa[node] - 1;
    while (i > 0 && !seen[orda[i]]) {
        DFS(orda[i]);
        i--;
    }
    int j = wb[node] - 1;
    while (j > 0 && !seen[ordb[j]]) {
        DFS(ordb[j]);
        j--;
    }
}

bool win(int n, int x) {
    for (int i = 1; i <= n; i++) {
        seen[i] = false;
    }
    nodes = 0;
    DFS(x);
    return nodes == n;
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            orda[i] = ordb[i] = i;
            ok[i] = '0';
            seen[i] = false;
        }
        sort(orda + 1, orda + n + 1, [&](int x, int y) {
            return a[x] < a[y];
        });
        sort(ordb + 1, ordb + n + 1, [&](int x, int y) {
            return b[x] < b[y];
        });
        for (int i = 1; i <= n; i++) {
            wa[orda[i]] = i;
            wb[ordb[i]] = i;
        }
        int left = 1, right = n, ans = n + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (win(n, orda[mid])) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        for (int i = ans; i <= n; i++) {
            ok[orda[i]] = '1';
        }
        ok[n + 1] = 0;
        cout << (ok + 1) << "\n";
    }
    return 0;
}