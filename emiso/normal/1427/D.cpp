#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int t, n;
vector<int> a;
vector<vector<int>> ans;

vector<int> op(vector<int> b, vector<int> blk) {
    int sum = 0;
    vector<int> ret;
    //reverse(blk.begin(), blk.end());
    int tmp = 0;
    for(int x : blk) tmp += x;
    assert(tmp == b.size());

    for(int x : blk) {
        sum += x;
        for(int i = b.size() - sum; i < b.size() - sum + x; i++)
            ret.push_back(b[i]);
    }
    return ret;
}

vector<int> comp(vector<int> blk) {
    vector<int> ret;
    for(int x : blk) if(x) ret.push_back(x);
    return ret;
}

int main() {
    scanf("%d", &n);
    a.resize(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    while(!is_sorted(a.begin(), a.end())) {
        if(a[0] == 0 || a.back() == n-1) {
            vector<int> cur;
            int idx = n-1, pref = 0;
            while(a[pref] == pref) pref++;

            while(a[idx] == idx) {
                cur.push_back(1);
                idx--;
            }

            int nxt = idx;
            while(a[idx] != nxt) idx--;
            cur.push_back(nxt - idx + 1);
            cur.push_back(idx - pref);
            cur.push_back(pref);

            ans.push_back(comp(cur));
            a = op(a, ans.back());
        } else {
            vector<int> cur;
            int p0 = -1;
            for(int i = 0; i < n; i++)
                if(a[i] == 0) p0 = i;

            int flag = 1;
            for(int i = p0, j = 0; i < n && flag; i++, j++)
                if(a[i] != j) flag = 0;

            if(flag) flag = (n - p0);

            cur.push_back(flag);
            int pn = -1;
            for(int i = 0; i < n; i++)
                if(a[i] == flag) pn = i;
            cur.push_back(n - pn - flag);

            int i, j;
            for(i = n-1, j = 0; j < pn && a[j] == i; i--, j++);

            cur.push_back(pn - j);
            for(int z = j-1; z >= 0; z--) cur.push_back(1);

            ans.push_back(comp(cur));
            a = op(a, ans.back());
        }
    }

    printf("%d\n", ans.size());
    for(auto tt : ans) {
        printf("%d", tt.size());
        reverse(tt.begin(), tt.end());
        for(int x : tt) printf(" %d", x);
        puts("");
    }
    return 0;
}