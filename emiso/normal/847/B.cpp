#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

typedef vector<int> vi;

int a[N];
vector<vi> v;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    v.push_back({a[0]});
    for (int i = 1; i < n; ++i) {
        int lo = 0, hi = v.size() - 1, ps = -1;
        while (lo <= hi) {
            int md = (lo + hi) / 2;
            if (v[md].back() > a[i]) {
                lo = md + 1;
            } else {
                ps = md;
                hi = md - 1;
            }
        }
        if (ps == -1) {
            v.push_back({a[i]});
        } else {
            v[ps].push_back(a[i]);
        }
    }
    for (auto i : v) {
        for (int j = 0; j < i.size(); ++j) {
            printf("%d%c", i[j], " \n"[j == i.size() - 1]);
        }
    }
    return 0;
}