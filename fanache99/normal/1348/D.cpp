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

int smallest(int start, int nights) {
    return start * nights;
}

int largest(int start, int nights) {
    return start * ((1 << (nights + 1)) - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        int k = 1, start = 1;
        int before = 1;
        n--;
        while (largest(start, k) < n)
            k++;
        cout << k << "\n";
        for (int i = 1; i <= k; i++) {
            int left = before, right = 2 * before, answer = -1;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (smallest(middle, k - i) <= n - middle && n - middle <= largest(middle, k - i)) {
                    answer = middle;
                    break;
                }
                if (smallest(middle, k - i) > n - middle)
                    right = middle - 1;
                else
                    left = middle + 1;
            }
            assert(before <= answer && answer <= 2 * before);
            n -= answer;
            cout << answer - before << " ";
            before = answer;
        }
        cout << "\n";
        assert(n == 0);
    }
    return 0;
}