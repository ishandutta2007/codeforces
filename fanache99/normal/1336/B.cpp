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

const int MAXN = 100000;
const long long INF = 4000000000000000000LL;

int a[1 + MAXN], b[1 + MAXN], c[1 + MAXN];

long long cost(int x, int y, int z) {
    return 1LL * (x - y) * (x - y) + 1LL * (x - z) * (x - z) + 1LL * (y - z) * (y - z);
}

long long best(int *v, int n, int *v1, int n1, int *v2, int n2) {
    long long answer = INF;
    int i = 1, i1 = 1, i2 = 1;
    while (i <= n && (v[i] < v1[1] || v[i] < v2[1]))
        i++;
    while (i <= n) {
        while ((i1 < n1 && v1[i1 + 1] <= v[i] && cost(v[i], v1[i1 + 1], v2[i2]) <= cost(v[i], v1[i1], v2[i2])) || (i2 < n2 && v2[i2 + 1] <= v[i] && cost(v[i], v1[i1], v2[i2 + 1]) <= cost(v[i], v1[i1], v2[i2])))
            if (i1 < n1 && v1[i1 + 1] <= v[i] &&  cost(v[i], v1[i1 + 1], v2[i2]) <= cost(v[i], v1[i1], v2[i2]))
                i1++;
            else
                i2++;
        answer = min(answer, cost(v[i], v1[i1], v2[i2]));
        i++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int na, nb, nc;
        cin >> na >> nb >> nc;
        for (int i = 1; i <= na; i++)
            cin >> a[i];
        for (int i = 1; i <= nb; i++)
            cin >> b[i];
        for (int i = 1; i <= nc; i++)
            cin >> c[i];
        sort(a + 1, a + na + 1);
        sort(b + 1, b + nb + 1);
        sort(c + 1, c + nc + 1);
        cout << min(best(a, na, b, nb, c, nc), min(best(b, nb, c, nc, a, na), best(c, nc, a, na, b, nb))) << "\n";
    }
    return 0;
}