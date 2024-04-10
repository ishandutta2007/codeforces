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
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
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

const int MAXN = 100;

int v[1 + MAXN];
bool seen[1 + MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            seen[i] = false;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            seen[v[i]] = true;
        }
        int sum = 0, total = 0;
        for (int i = 1; i <= n; i++)
            if (seen[i]) {
                sum += i;
                total++;
            }
        if (total > k) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n && total < k; i++)
            if (!seen[i]) {
                seen[i] = true;
                total++;
                sum += i;
            }
        cout << k * n << "\n";
        for (int step = 1; step <= n; step++)
            for (int i = 1; i <= n; i++)
                if (seen[i])
                    cout << i << " ";
        cout << "\n";
    }
    return 0;
}