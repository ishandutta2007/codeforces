#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(0);


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pii> b(n);
    vector<int> cur(n);
    vector<int> wh(n);
    int ind = -1;
    int ix = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
        cur[i] = i;
        wh[i] = i;

        int x = a[i];
        bool fl = false;
        while(x > 0) {
            if(x % 10 != 4 && x % 10 != 7) {
                fl = true;
                break;
            }
            x /= 10;
        }
        if(!fl) {
            ind = i;
            ix = i;
        }
    }

    sort(b.begin(), b.end());

    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i].f)
            fl = true;
    }

    if(!fl) {
        cout << 0 << endl;
        return 0;
    }

    if(ind == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<pii> ans;
    for(int i = 0; i < n; i++) {
        if(b[i].s == cur[i] || b[i].s == ix) {
            continue;
        }

        if(ind != i) {
            ans.emplace_back(ind, i);
            swap(a[ind], a[i]);
            wh[cur[i]] = ind;
            wh[cur[ind]] = i;
            swap(cur[i], cur[ind]);
            ind = i;
        }

//        for(auto x : a)
//            cout << x << ' ';
//        cout << endl;

        int j = wh[b[i].s];
        ans.emplace_back(i, j);
        swap(a[i], a[j]);
        wh[ix] = j;
        wh[b[i].s] = i;
        cur[i] = b[i].s;
        cur[j] = ix;

//        swap(cur[wh[b[i].s]], cur[ind]);
        ind = j;

//        for(auto x : a)
//            cout << x << ' ';
//        cout << endl;
    }

    cout << ans.size() << endl;
    for(auto p : ans) {
        cout << p.f + 1 << ' ' << p.s + 1 << endl;
    }
}