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
using namespace std::chrono;

const int MAXN = 20000;
const int DIRECTIONS = 4;
const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

char s[1 + MAXN + 1];
bool points[1 + MAXN][DIRECTIONS];
int divs[1 + MAXN];
long long divsSum[1 + MAXN];

void precompute(int n) {
    for (int i = 1; i <= n; i++) {
        points[i][UP] = (s[i] == 'U');
        points[i][LEFT] = (s[i] == 'L');
        points[i][DOWN] = (s[i] == 'D');
        points[i][RIGHT] = (s[i] == 'R');
    }
    for (int i = 2; i <= n; i++) {
        for (int d = 2; d * d <= i; d++) {
            if (i % d == 0) {
                divs[i] += (d % 2 == 0);
                if (i / d != d) {
                    divs[i] += ((i / d) % 2 == 0);
                }
            }
        }
        divsSum[i] = divsSum[i - 2] + divs[i];
    }
}

int colSum[1 + MAXN];

long long oneCol(int n) {
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        colSum[i] = ((points[i][UP] & points[i - 1][DOWN]) ? colSum[i - 2] + 1 : 0);
        ans += colSum[i];
    }
    return ans;
}

int rowSum[1 + MAXN];

long long oneRow(int n) {
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        rowSum[i] = ((points[i][LEFT] & points[i - 1][RIGHT]) ? rowSum[i - 2] + 1 : 0);
        ans += rowSum[i];
    }
    return ans;
}

int mask[1 + MAXN];

void computeMasks(int n, int c) {
    for (int i = 1; i <= n; i++) {
        mask[i] = (((i - c >= 1) & points[i - c][DOWN]) << UP) |
                  (((i - 1 >= 1) & points[i - 1][RIGHT]) << LEFT) |
                  (((i + c <= n) & points[i + c][UP]) << DOWN) |
                  (((i + 1 <= n) & points[i + 1][LEFT]) << RIGHT);
    }
}

bool hasOneBit[16] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};

inline bool topLeft(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << RIGHT))];
}

inline bool topMid(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << RIGHT) | (1 << LEFT))];
}

inline bool topRight(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << LEFT))];
}

inline bool midLeft(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << UP) | (1 << RIGHT))];
}

inline bool midMid(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << LEFT) | (1 << RIGHT) | (1 << UP))];
}

inline bool midRight(int i) {
    return hasOneBit[mask[i] & ((1 << DOWN) | (1 << UP) | (1 << LEFT))];
}

inline bool bottomLeft(int i) {
    return hasOneBit[mask[i] & ((1 << UP) | (1 << RIGHT))];
}

inline bool bottomMid(int i) {
    return hasOneBit[mask[i] & ((1 << UP) | (1 << RIGHT) | (1 << LEFT))];
}

inline bool bottomRight(int i) {
    return hasOneBit[mask[i] & ((1 << UP) | (1 << LEFT))];
}

int topMidSum, bottomMidSum, midMidSum;

inline bool topRow(int i, int c) {
    return (i >= c) & topLeft(i - c + 1) & (topMidSum >= c - 2) & topRight(i);
}

inline bool midRow(int i, int c) {
    return (i >= c) & midLeft(i - c + 1) & (midMidSum >= c - 2) & midRight(i);
}

inline bool bottomRow(int i, int c) {
    return (i >= c) & bottomLeft(i - c + 1) & (bottomMidSum >= c - 2) & bottomRight(i);
}

int topRowsSum[1 + MAXN];

long long twoRowsFixedCols(int n, int c) {
    computeMasks(n, c);
    long long ans = 0;
    midMidSum = 0, bottomMidSum = 0, topMidSum = 0;
    for (int i = 1; i <= n; i++) {
        topRowsSum[i] = topRow(i, c) + (midRow(i, c) ? topRowsSum[i - c] : 0);
        if (bottomRow(i, c)) {
            ans += topRowsSum[i - c];
        }
        midMidSum = (midMid(i) ? 1 + midMidSum : 0);
        bottomMidSum = (bottomMid(i) ? 1 + bottomMidSum : 0);
        topMidSum = (topMid(i) ? 1 + topMidSum : 0);
    }
    return ans;
}

long long leftRight(int n) {
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        rowSum[i] = ((points[i][LEFT] & points[i - 1][RIGHT]) ? rowSum[i - 2] + 1 : 0);
        ans += divsSum[2 * rowSum[i]];
    }
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    srand(time(0));

    cin >> (s + 1);
    int n = strlen(s + 1);
//    int n = MAXN;
//    for (int i = 1; i <= n; i++) {
//        switch(rand() % 4) {
//            case 0:
//                s[i] = 'U';
//                break;
//            case 1:
//                s[i] = 'L';
//                break;
//            case 2:
//                s[i] = 'D';
//                break;
//            case 3:
//                s[i] = 'R';
//                break;
//        }
//    }
//    cout << (s + 1) << "\n";

    precompute(n);

    long long answer = oneCol(n) + oneRow(n);
    for (int c = 2; 2 * c <= n; c++) {
        answer += twoRowsFixedCols(n, c);
    }
    answer -= leftRight(n);

    cout << answer << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}