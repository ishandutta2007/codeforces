#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

const int C = 4000000;

string one_iter[C];
string two_iter[C];
int prev_sum[C];

void solve(bool read) {
    for (int i = 1; i < C; ++i) {
        int cur = i;
        int sum_digs = 0;
        while (cur) {
            sum_digs += cur % 10;
            cur /= 10;
        }
        if (sum_digs < 10) {
            cur = i;
            while (cur) {
                one_iter[i] += (char)('0' + cur % 10);
                cur /= 10;
                if (cur) {
                    one_iter[i] += '+';
                }
            }
            reverse(all(one_iter[i]));
        }
    }

    //cout << "here" << endl;

    int repr[20];
    for (int i = 1; i < C; ++i) {
        if (one_iter[i].size() > 0) {
            two_iter[i] = one_iter[i];
            prev_sum[i] = i;
            continue;
        }
        int cnt = 0;
        int cur = i;
        while (cur) {
            repr[cnt++] = cur % 10;
            cur /= 10;
        }
        reverse(repr, repr + cnt);
        int between = cnt - 1;
        for (int mask = (1 << between) - 1; mask > 0; --mask) {
            int sum = 0;
            int last = 0;
            string cur_repr;
            for (int j = 0; j < cnt; ++j) {
                last = last * 10 + repr[j];
                cur_repr += (char)('0' + repr[j]);
                if (j + 1 == cnt || (mask & (1 << j))) {
                    sum += last;
                    last = 0;
                    if (j + 1 < cnt) {
                        cur_repr += '+';
                    }
                }
            }
            if (sum < C && !one_iter[sum].empty()) {
                prev_sum[i] = sum;
                two_iter[i] = cur_repr;
                break;
            }
        }
    }

    /*for (int i = 0; i < 100; ++i) {
        cout << i << " " << two_iter[i] << endl;
    }*/

    //read = false;
    int n;
    if (read) {
        cin >> n;
    } else {
        n = 200000;
    }
    string s;
    if (read) {
        cin >> s;
    } else {
        for (int i = 0; i < n; ++i) {
            s += (char)('0' + rand() % 10);
        }
    }
    while (true) {
        int last = 0;
        int sum = 0;
        string cur_repr;
        for (int j = 0; j < n; ++j) {
            last = last * 10 + s[j] - '0';
            cur_repr += s[j];
            if (j + 1 == n || rand() % 10 != 0) {
                sum += last;
                last = 0;
                if (j + 1 < n) {
                    cur_repr += '+';
                }
            }
        }

        if (sum < C && !two_iter[sum].empty()) {
            cout << cur_repr << endl;
            cout << two_iter[sum] << endl;
            cout << one_iter[prev_sum[sum]] << endl;
            return;
        }
    }

}