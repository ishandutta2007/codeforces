#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

vector <int> x, y;

int get(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int count(vector <int> idx) {
    int res = 0;
    for (int i = 0; i < (int)idx.size(); ++i) {
        int j = (i + 1) % idx.size();
        res += get(idx[i], idx[j]);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    int mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
    for (int i = 0; i < n; ++i) {
        mnx = min(mnx, x[i]);
        mxx = max(mxx, x[i]);
        mny = min(mny, y[i]);
        mxy = max(mxy, y[i]);
    }
    vector <int> ans(n - 2);
    for (int i = 1; i < (int)ans.size(); ++i) ans[i] = 2 * (mxx - mnx + mxy - mny);
    vector <int> pts;
    for (int i = 0; i < n; ++i) {
        if (x[i] == mnx || x[i] == mxx || y[i] == mny || y[i] == mxy) {
            pts.push_back(i);
        }
    }
    for (auto i : pts) {
        for (auto j : pts) {
            for (int k = 0; k < n; ++k) {
                if (i != j && i != k && j != k) {
                    vector <int> cur = {i, j, k};
                    ans[0] = max(ans[0], count(cur));
                }
            }
        }
    }
    for (auto t : ans) {
        cout << t << ' ';
    }
}