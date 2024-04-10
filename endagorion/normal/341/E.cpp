#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cassert>
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

int a[1000];
vector< pair<int, int> > ans;

int N;
int p = -1;

int next() {
    ++p;
    while (p < N && a[p] == 0) {
        ++p;
    }
    return p;
}

void move(int i, int j) {
    ans.pb(mp(i, j));
    assert(a[i] <= a[j]);
    a[j] -= a[i];
    a[i] *= 2;
}

void threeIntoTwo(int i, int j, int k) {
    while (true) {
        if (a[i] > a[j]) {
            swap(i, j);
        }
        if (a[j] > a[k]) {
            swap(j, k);
        }
        if (a[i] > a[j]) {
            swap(i, j);
        }
        if (a[i] == 0) {
            return;
        }
        int q = a[j] / a[i];
        while (q > 0) {
            if (q & 1) {
                move(i, j);
            } else {
                move(i, k);
            }
            q /= 2;
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    int not0Count = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i]) {
            ++not0Count;
        }
    }

    if (not0Count < 2) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> cur(3);
    for (int i = 0; i < 3; ++i) {
        cur[i] = next();
    }
    while (*max_element(all(cur)) < N) {
        threeIntoTwo(cur[0], cur[1], cur[2]);
        for (int i = 0; i < 3; ++i) {
            if (a[cur[i]] == 0) {
                cur[i] = next();
            }
        }
    }

    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
    
	return 0;
}