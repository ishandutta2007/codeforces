#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>

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

const int MOD = 998244353;
const int MAXN = 200000;

int v[1 + MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    int howMany = 1, before = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] >= n - k + 1) {
            sum += v[i];
            if (before != 0)
                howMany = 1LL * howMany * (i - before) % MOD;
            before = i;
        }
    }
    cout << sum << " " << howMany << "\n";
    return 0;
}