#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>

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

const int MAXVAL = 5000;

int v[1 + 3 * MAXVAL];

//ofstream cout("output.out");

void binary(int x, int bits) {
    for (int i = 0; i < bits; i++)
        if (x & (1 << i))
            cout << "1";
        else
            cout << "0";
    cout << "    ";
}

void output(int a, int b, int c, int bits) {
    cout << a << "   " << b << "   " << c << "             ";
    binary(a, bits);
    binary(b, bits);
    binary(c, bits);
    cout << "\n";
}

long long get(long long n) {
    int r = n % 3;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 3;
    int power = 1;
    while ((1LL << (2 * power)) - 1 < n)
        power++;
    n = (n - (1LL << (2 * (power - 1)))) / 3;
    long long a = 1LL << (2 * power - 2), b = 1LL << (2 * power - 1);
    for (int i = 0; i < power - 1; i++) {
        if (((n >> (2 * i)) & 3) == 0) {
        }
        if (((n >> (2 * i)) & 3) == 1) {
            a |= 1LL << (2 * i);
            b |= 1LL << (2 * i + 1);
        }
        if (((n >> (2 * i)) & 3) == 2) {
            a |= 1LL << (2 * i + 1);
            b |= 1LL << (2 * i);
            b |= 1LL << (2 * i + 1);
        }
        if (((n >> (2 * i)) & 3) == 3) {
            a |= 1LL << (2 * i);
            a |= 1LL << (2 * i + 1);
            b |= 1LL << (2 * i);
        }
    }
    if (r == 1)
        return a;
    if (r == 2)
        return b;
    if (r == 0)
        return a ^ b;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //ifstream cin("input.in");
    /*map<int, bool> seen;
    for (int step = 1, a = 1; step <= MAXVAL; step++) {
        while (seen[a])
            a++;
        int b = a + 1;
        while (seen[b] || seen[a ^ b])
            b++;
        seen[a] = seen[b] = seen[a ^ b] = true;
        //output(a, b, a ^ b, 10);
        v[3 * step - 2] = a;
        v[3 * step - 1] = b;
        v[3 * step] = a ^ b;
        cout << step << "\n";
    }
    for (int i = 1; i <= 3 * MAXVAL; i++)
        if (get(i) != v[i]) {
            cout << "Bad: " << i << " " << v[i] << " " << get(i) << "\n";
            return 0;
        } else
            if (i % 10 == 0)
                cout << "Ok: " << i << "\n";*/
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long n;
        cin >> n;
        cout << get(n) << "\n";
    }
    return 0;
}