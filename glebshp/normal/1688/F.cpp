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
#include <queue>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200 * 1000 + 100;

int tnum, n, m;
bool good[maxn];
vector <int> segs[maxn];
int cnt[maxn];
queue <int> segstoturn;
set <int> bad;
int lb[maxn];
int rb[maxn];
int a[maxn];
int b[maxn];
long long d[maxn];

void turnOn(int p) {
    good[p] = true;
    for (auto s : segs[p]) {
        cnt[s]--;
        if (cnt[s] == 0) {
            segstoturn.push(s);
        }
    }
}

void clearTest() {
    bad.clear();
    segstoturn = queue<int>();
    
    for (int i = 0; i <= n; i++) {
        good[i] = false;
        segs[i].clear();
    }
    for (int i = 0; i < m; i++) {
        cnt[i] = 2;
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tnum);
    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d%d", &n, &m);

        clearTest();
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        d[0] = 0ll;
        for (int i = 0; i < n; i++) {
            d[i + 1] = d[i] + a[i] - b[i];
        }

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &lb[i], &rb[i]);
            lb[i]--;
            segs[lb[i]].pb(i);
            segs[rb[i]].pb(i);
        }

        for (int i = 0; i <= n; i++) {
            if (d[i] == 0ll) {
                turnOn(i);
            } else {
                bad.insert(i);
            }
        }

        while (!segstoturn.empty()) {
            int curseg = segstoturn.front();
            segstoturn.pop();

            set<int>::iterator it = bad.lower_bound(lb[curseg]);
            while (it != bad.end() && *it <= rb[curseg]) {
                turnOn(*it);
                it++;
            }

            while (true) {
                set<int>::iterator it = bad.lower_bound(lb[curseg]);
                if (it != bad.end() && *it <= rb[curseg]) {
                    bad.erase(*it);
                } else {
                    break;
                }
            }
        }

        bool ans = true;
        for (int i = 0; i <= n; i++) {
            if (!good[i]) {
                ans = false;
            }
        }

        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}