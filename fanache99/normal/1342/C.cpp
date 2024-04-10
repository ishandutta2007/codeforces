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

const int MAXA = 200;
const int MAXB = 200;

long long brute(int a, int b, long long l, long long r) {
    long long answer = 0;
    for (long long x = l; x <= r; x++)
        if (x % a % b != x % b % a)
            answer++;
    return answer;
}

int sum[MAXA * MAXB];

void precompute(int a, int b) {
    for (int i = 1; i < a * b; i++) {
        sum[i] = sum[i - 1];
        if (i % a % b != i % b % a)
            sum[i]++;
    }
}

long long fast(int a, int b, long long l, long long r) {
    if (a == 1 || b == 1)
        return 0;
    int p = a * b;
    long long cl = l / p, cr = r / p;
    int rl = l % p, rr = r % p;
    if (cl == cr)
        return sum[rr] - (rl == 0 ? 0 : sum[rl - 1]);
    else
        return (cr - cl - 1) * sum[p - 1] + (sum[p - 1] - (rl == 0 ? 0 : sum[rl - 1])) + sum[rr];
}

void verify() {
    srand(time(0));
    for (int step = 1; step <= 10000; step++) {
        int a = rand() % 200 + 1, b = rand() % 200 + 1;
        long long l = rand() % 1000000, r = rand() % 10000 + l;
        precompute(a, b);
        long long ans1 = brute(a, b, l, r), ans2 = fast(a, b, l, r);
        if (ans1 == ans2)
            cout << "Ok\n";
        else {
            cout << "Bad: " << a << " " << b << " " << l << " " << r << " " << ans1 << " " << ans2 << "\n";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    //verify();
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int a, b, q;
        cin >> a >> b >> q;
        precompute(a, b);
        for (int i = 1; i <= q; i++) {
            long long l, r;
            cin >> l >> r;
            cout << fast(a, b, l, r) << " ";
        }
        cout << "\n";
    }
    return 0;
}