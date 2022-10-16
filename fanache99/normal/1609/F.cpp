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
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 1000000;
const long long INF = 1e18;
const int MAXLOG = 63;

long long v[1 + MAXN];
int bits[1 + MAXN];
//int stMin[1 + MAXN], stMax[1 + MAXN];
//int lMin[1 + MAXN], rMin[1 + MAXN], lMax[1 + MAXN], rMax[1 + MAXN];
//
//void traverse(int n) {
//    int topMin = 0, topMax = 0;
//    for (int i = 1; i <= n; i++) {
//        while (topMin > 0 && v[i] <= v[stMin[topMin]]) {
//            rMin[stMin[topMin]] = i;
//            topMin--;
//        }
//        lMin[i] = stMin[topMin];
//        topMin++;
//        stMin[topMin] = i;
//        while (topMax > 0 && v[i] >= v[stMax[topMax]]) {
//            rMax[stMax[topMax]] = i;
//            topMax--;
//        }
//        lMax[i] = stMax[topMax];
//        topMax++;
//        stMax[topMax] = i;
//    }
//    while (topMin > 0) {
//        rMin[stMin[topMin]] = n + 1;
//        topMin--;
//    }
//    while (topMax > 0) {
//        rMax[stMax[topMax]] = n + 1;
//        topMax--;
//    }
//
//    for (int i = 1; i <= n; i++) {
//
//    }
//}

long long ans = 0;
#define bitCnt __builtin_popcountll

void updateMin(long long &mn, int &bitsMn, long long newMn, int newBitsMn) {
    if (newMn < mn) {
        mn = newMn;
        bitsMn = newBitsMn;
    }
}

void updateMax(long long &mx, int &bitsMx, long long newMx, int newBitsMx) {
    if (newMx > mx) {
        mx = newMx;
        bitsMx = newBitsMx;
    }
}

void solve(int left, int right) {
    if (left == right) {
        ans++;
        return;
    }
    int middle = (left + right) / 2;

    // min and max on left
    {
        long long mn = INF + 1, mx = -1;
        int bitsMn, bitsMx;
        for (int i = middle, j = middle + 1; i >= left; i--) {
            updateMin(mn, bitsMn, v[i], bits[i]), updateMax(mx, bitsMx, v[i], bits[i]);
            while (j <= right && v[j] >= mn && v[j] <= mx) {
                j++;
            }
            if (bitsMn == bitsMx) {
                ans += j - (middle + 1);
            }
        }
    }

    // min and max on right
    {
        long long mn = INF + 1, mx = -1;
        int bitsMn, bitsMx;
        for (int i = middle + 1, j = middle; i <= right; i++) {
            updateMin(mn, bitsMn, v[i], bits[i]), updateMax(mx, bitsMx, v[i], bits[i]);
            while (j >= left && v[j] > mn && v[j] < mx) {
                j--;
            }
            if (bitsMn == bitsMx) {
                ans += middle - j;
            }
        }
    }

    // min on left, max on right
    {
        long long mn = INF + 1, mx = -1;
        int bitsMn, bitsMx;
        vector<int> cnt(MAXLOG, 0);
        long long mx1 = v[middle + 1], mx2 = -1;
        int bitsMx1 = bits[middle + 1], bitsMx2;
        for (int i = middle, j1 = middle + 1, j2 = middle + 1; i >= left; i--) {
            updateMin(mn, bitsMn, v[i], bits[i]), updateMax(mx, bitsMx, v[i], bits[i]);
            while (j2 <= right && v[j2] >= mn) {
                updateMax(mx2, bitsMx2, v[j2], bits[j2]);
                cnt[bitsMx2]++;
                j2++;
            }
            while (j1 < j2 && mx1 <= mx) {
                cnt[bitsMx1]--;
                j1++;
                updateMax(mx1, bitsMx1, v[j1], bits[j1]);
            }
            ans += cnt[bitsMn];
        }
    }

    // min on right, max on left
    {
        long long mn = INF + 1, mx = -1;
        int bitsMn, bitsMx;
        vector<int> cnt(MAXLOG, 0);
        long long mx1 = v[middle], mx2 = -1;
        int bitsMx1 = bits[middle], bitsMx2;
        for (int i = middle + 1, j1 = middle, j2 = middle; i <= right; i++) {
            updateMin(mn, bitsMn, v[i], bits[i]), updateMax(mx, bitsMx, v[i], bits[i]);
            while (j2 >= left && v[j2] > mn) {
                updateMax(mx2, bitsMx2, v[j2], bits[j2]);
                cnt[bitsMx2]++;
                j2--;
            }
            while (j1 > j2 && mx1 < mx) {
                cnt[bitsMx1]--;
                j1--;
                updateMax(mx1, bitsMx1, v[j1], bits[j1]);
            }
            ans += cnt[bitsMn];
        }
    }

    solve(left, middle);
    solve(middle + 1, right);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        bits[i] = bitCnt(v[i]);
    }
//    traverse(n);
    solve(1, n);
    cout << ans << "\n";
    return 0;
}