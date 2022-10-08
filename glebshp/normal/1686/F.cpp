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

const int maxn = 1000;

int n;
int p[maxn];
int where[maxn];
int nxt[maxn];
int clr[maxn];

pair <int, int> getValue() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        clr[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (clr[i] == -1) {
            int cur = i;
            while (clr[cur] == -1) {
                clr[cur] = cnt;
                cur = nxt[cur];
            }

            cnt++;
        }
    }

    int value = 0;
    for (int i = 0; i < n; i++) {
        value += abs(i - p[nxt[i]]);
    }

    return mp(value, cnt);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        for (int i = 0; i < n; i++) {
            where[p[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            nxt[i] = where[i];
        }

        pair <int, int> res = getValue();

        while (res.sc > 1) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(nxt[i], nxt[j]);
                    pair <int, int> nres = getValue();

                    if (nres.fs == res.fs + 2 && nres.sc == res.sc - 1) {
                        res = nres;
                    } else {
                        swap(nxt[i], nxt[j]);
                    }
                }
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cout << cur + 1 << ' ';
            cur = nxt[cur];
        }
        cout << endl;
    }

    return 0;
}