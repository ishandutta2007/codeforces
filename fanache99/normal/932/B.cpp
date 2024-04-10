#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    return ch;
}

const int MAXVAL = 1000000;
const int MAXSMALL = 9;

int g[1 + MAXVAL];
vector<int> where[1 + MAXSMALL];

int Product(int x) {
    int p = 1;
    while (x) {
        if (x % 10)
            p *= x % 10;
        x /= 10;
    }
    return p;
}

void Precompute(int n) {
    for (int i = 0; i <= n; i++) {
        if (i < 10)
            g[i] = i;
        else
            g[i] = g[Product(i)];
        where[g[i]].push_back(i);
    }
}

int BinarySearch(int x, int k) {
    int left = 0, right = where[k].size() - 1, answer = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (where[k][middle] <= x) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return answer + 1;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    Precompute(MAXVAL);
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int a = Read(), b = Read(), k = Read();
        printf("%d\n", BinarySearch(b, k) - BinarySearch(a - 1, k));
    }
    return 0;
}