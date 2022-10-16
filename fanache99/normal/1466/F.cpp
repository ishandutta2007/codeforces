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

const int MAXM = 500000;
const int MOD = 1000000007;

int dad[1 + MAXM], h[1 + MAXM];
bool bad[1 + MAXM];

int findDad(int node) {
    if (dad[node] == node) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int n, m, answer = 1;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        dad[i] = i;
        h[i] = 1;
        bad[i] = false;
    }
    vector<int> sol;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            int dx = findDad(x);
            if (!bad[dx]) {
                answer = 2 * answer % MOD;
                sol.push_back(i);
                bad[dx] = true;
            }
        } else {
            int x, y;
            cin >> x >> y;
            int dx = findDad(x), dy = findDad(y);
            if (dx != dy) {
                if (h[dx] > h[dy]) {
                    swap(dx, dy);
                }
                if (!bad[dx] || !bad[dy]) {
                    answer = 2 * answer % MOD;
                    sol.push_back(i);
                }
                dad[dx] = dy;
                if (h[dx] == h[dy]) {
                    h[dy]++;
                }
                bad[dy] = bad[dx] || bad[dy];
            }
        }
    }
    cout << answer << " " << sol.size() << "\n";
    for (auto it : sol) {
        cout << it << " ";
    }
    return 0;
}