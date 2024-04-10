#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN (1 << 21)

int n, m, q, a[MN];
ll lo[MN], hi[MN], ans;
vector<vector<int>> workit;

vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> res(a.size()+b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
    return res;
}

int smol(vector<int> &a, int x) {
    auto lb = lower_bound(a.begin(), a.end(), x);
    return lb - a.begin();
}

int bigi(vector<int> &a, int x) {
    auto ub = upper_bound(a.begin(), a.end(), x);
    return a.end() - ub;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < (1 << n); i++) {
        scanf("%d", &a[i]);

        for(auto &v : workit) {
            int tmp = smol(v, a[i]);
            lo[2*v.size()] += tmp;

            tmp = bigi(v, a[i]);
            hi[2*v.size()] += tmp;
            ans += tmp;
        }

        vector<int> tmp(1, a[i]);
        while(!workit.empty() && tmp.size() == workit.back().size()) {
            tmp = merge(tmp, workit.back());
            workit.pop_back();
        }
        workit.push_back(tmp);
    }

    scanf("%d", &m);
    while(m--) {
        scanf("%d", &q);
        do {
            ans -= hi[1<<q];
            ans += lo[1<<q];
            swap(hi[1<<q], lo[1<<q]);
        } while(--q > 0);
        printf("%lld\n", ans);
    }

    return 0;
}