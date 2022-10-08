#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

/*
vector <int> ans;

bool check(int n, int k, const vector <int>& queens) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = false;
            for (int p = 0; p < n * n; p++) {
                if (queens[p] == 1) {
                    int r = p / n;
                    int c = p % n;
                    if (r == i || c == j || r - c == i - j) {
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag) {
                return false;
            }
        }
    }

    return true;
}

bool go(int n, int k) {
    vector <int> queens(n * n, 0);
    for (int i = 0; i < k; i++) {
        queens[n * n - 1 - i] = 1;
    }
    do {
        if (check(n, k, queens)) {
            ans = queens;

            return true;
        }
    } while (next_permutation(queens.begin(), queens.end()));

    return false;
}
*/

void printDiagonal(int s, int len) {
    for (int i = 0; i < len; i++) {
        cout << s + i << ' ' << s + len - 1 - i << endl;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    
    cin >> n;
    /*
    int k = 1;
    while (!go(n, k)) {
        k++;
    }
    for (int i = 0; i < n * n; i++) {
        printf("%d", ans[i]);
        if (i % n == n - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    
    return 0;
    */

    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;

        return 0;
    }

    if (n == 2) {
        cout << 1 << endl;
        cout << 1 << ' ' << 1 << endl;

        return 0;
    }

    if (n == 3) {
        cout << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 2 << ' ' << 2 << endl;

        return 0;
    }

    int k = 1;
    while ((n - k) * 2 - 1 > k) {
        k++;
    }

    if (k % 2 == 1) {
        cout << k << endl;
        printDiagonal(1, k / 2 + 1);
        printDiagonal(k / 2 + 2, k / 2);
    } else {
        cout << k << endl;
        printDiagonal(1, k / 2);
        printDiagonal(k / 2 + 1, k / 2 - 1);
        cout << k / 2 << ' ' << k << endl;
    }

    return 0;
}