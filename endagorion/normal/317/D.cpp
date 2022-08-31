#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int mu[30];
int mve[31];

int count(int M) {
    int res = M - 1;
    for (int k = 2; (1 << k) <= M; ++k) {
        res -= count((int)floor(pow(1.0 * M, 1.0 / k)));
    }
    return res;
}

/*int game(int mask, map<int, int> &memo) {
    if (memo.count(mask) > 0) {
        return memo[mask];
    }
    bool gr[30];
    for (int i = 0; i < 30; ++i) {
        gr[i] = false;
    }
    for (int i = 1; i <= 30; ++i) {
        if (mask & (1 << (i - 1))) {
            int mm = mask & ~mve[i];
            gr[game(mm, memo)] = true;
        }
    }
    int x = 0;
    while (gr[x]) {
        ++x;
    }
    return memo[mask] = x;
}*/

int game[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;

    mu[1] = 1;
    for (int i = 2; i <= 30; ++i) {
        for (int j = 2; j <= i; ++j) {
            if (i % j == 0) {
                if (i % (j * j) == 0) {
                    mu[i] = 0;
                } else {
                    mu[i] = -mu[i / j];
                }
                break;
            }
        }
    }

    for (int i = 1; i <= 30; ++i) {
        for (int j = i; j <= 30; j += i) {
            mve[i] |= 1 << (j - 1);
        }
    }

    int gr = 1;
    map<int, int> memo;
    for (int i = 1; i <= 30; ++i) {
        int up = (int)floor(pow(1.0 * N, 1.0 / i)), down = (int)floor(pow(1.0 * N, 1.0 / (i + 1)));
        if ((count(up) - count(down)) % 2 == 1) {
            //cerr << i << '\n';
            gr ^= game[i];
        }
    }

    if (gr) {
        cout << "Vasya\n";
    } else {
        cout << "Petya\n";
    }

	return 0;
}