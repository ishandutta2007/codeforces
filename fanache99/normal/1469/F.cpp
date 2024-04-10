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
#include <unordered_set>

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

const int MAXN = 200000;
const int MAXVAL = 1000000;

int v[1 + MAXN];
int sum[1 + MAXVAL + 1];

bool check(int n, int k, int limit) {
    for (int i = 0; i <= limit + 1; i++) {
        sum[i] = 0;
    }
    sum[0] = 1;
    long long total = 1;
    for (int j = 1, i = 0; j <= n && i <= limit - 2; j++) {
        int l = i + v[j] / 2 + 1, r = i + v[j] / 2 + 1;
        if (v[j] % 2 == 0) {
            l--;
        }
        l = min(l, limit);
        r = min(r, limit);
        sum[i + 2] += 2;
        sum[l + 1]--;
        sum[r + 1]--;
        total--;
        total += l - (i + 2) + 1;
        total += r - (i + 2) + 1;
        sum[i]--;
        while (sum[i] == 0) {
            i++;
            sum[i + 1] += sum[i];
        }
    }
    return total >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n, k;
    long long white = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        white += v[i] - 2;
    }
    if (white < k) {
        cout << "-1\n";
    } else {
        sort(v + 1, v + n + 1);
        reverse(v + 1, v + n + 1);
        int left = 1, right = MAXVAL, answer = MAXVAL;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (check(n, k, middle)) {
                answer = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}