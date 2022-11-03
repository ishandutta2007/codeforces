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

int inter(int l, int r, int lf, int rg) {
    return max(0, min(r, rg) - max(l, lf) + 1);
}

int main() {
    int al, ar, bl, br, k;
    cin >> al >> ar >> bl >> br >> k;

    vector<int> a;
    for(int i = 1; i <= 9; i++) {
        for(int mask = 0; mask < (1 << i); mask++) {
            int x = 0;
            int p = 1;
            for(int j = 0; j < i; j++) {
                if(mask & (1 << j))
                    x += p * 4;
                else
                    x += p * 7;
                p *= 10;
            }
            a.push_back(x);
        }
    }

    a.push_back(-1);
    a.push_back(INF);

    sort(a.begin(), a.end());

    ld ans = 0;
    for(int i = 1; i + k < a.size(); i++) {
        ans += ld(inter(a[i - 1] + 1, a[i], al, ar)) / (ar - al + 1) *
                ld(inter(a[i + k - 1], a[i + k] - 1, bl, br)) / (br - bl + 1);

        ans += ld(inter(a[i - 1] + 1, a[i], bl, br)) / (br - bl + 1) *
                ld(inter(a[i + k - 1], a[i + k] - 1, al, ar)) / (ar - al + 1);

        if(k == 1) {
            ans -= ld(inter(a[i], a[i], bl, br)) / (br - bl + 1) *
                ld(inter(a[i], a[i], al, ar)) / (ar - al + 1);
        }
    }

    cout << setprecision(20) << fixed << ans << endl;
}