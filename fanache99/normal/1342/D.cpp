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

const int MAXN = 200000;
const int MAXK = 200000;

int limit[1 + MAXK], length[1 + MAXK];
vector<int> test[1 + MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        length[x]++;
    }
    for (int i = 1; i <= k; i++)
        cin >> limit[i];
    int sum = 0, answer = 0;
    for (int i = k; i >= 1; i--) {
        sum += length[i];
        answer = max(answer, (sum - 1) / limit[i] + 1);
    }
    cout << answer << "\n";
    for (int i = k, j = 1; i >= 1; i--)
        for (int p = 1; p <= length[i]; p++) {
            test[j].emplace_back(i);
            j++;
            if (j == answer + 1)
                j = 1;
        }
    for (int i = 1; i <= answer; i++) {
        cout << test[i].size() << " ";
        for (auto it : test[i])
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}