#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;



int n;
int a[1000000];
pair<int, int> l[1000000], r[1000000];
int d[5000000];
int ss = 1;
map<int, int> mm, mm1;


void change(int i, int x) {
    d[i] = x;
    while ((i >> 1) > 0) {
        i = i >> 1;
        int g = (i << 1);
        d[i] = d[g] + d[g + 1];
    }
}



// int rmq(int v, int vl, int vr, int l, int r) {
//     if (vl > r || vr < l) {
//         return 0;
//     }
//     if (l <= vl && vr <= r) {
//         return d[v];
//     }
//     int vm = (vl + vr) >> 1;
//     int g = (v << 1);
//     return rmq(g, vl, vm, l, r) + rmq(g + 1, vm + 1, vr, l, r);
// }


int rmq(int l, int r) {
    l = l + ss - 1;
    r = r + ss - 1;
    int ans = 0;
    while (l < r) {
        if ((l & 1) == 1) {
            ans += d[l];
        }
        if ((r & 1) == 0) {
            ans += d[r];
        }
        l = ((l + 1) >> 1);
        r = ((r - 1) >> 1);
    }
    if (l == r) {
        ans += d[l];
    }
    return  ans;
}


int main() {
    cin >> n;
    while (ss < n) {
        ss *= 2;
    }
    set<int> sss;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sss.insert(a[i]);
    }
    // if ((int)sss.size() == 1) {
    //     cout << 0 << endl;
    //     return 0;
    // } 
    for (int i = 0; i < n; i++) {
        mm[a[i]]++;
        l[i] = make_pair(mm[a[i]], i);
    }
    for (int i = n - 1; i >= 0; i--) {
        mm1[a[i]]++;
        r[i] = make_pair(mm1[a[i]], i);
    }
    for (int i = 0; i < n; i++) {
        d[ss + i] = 1;
    }
    for (int i = ss - 1; i >= 0; i--) {
        int g = (i << 1);
        d[i] = d[g] + d[g + 1];
    }
    sort(l, l + n);
    sort(r, r + n);
    int l1 = n - 1;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (l1 >= 0 && r[l1].first >= l[i].first) {
            change(ss + r[l1].second, 0);
            l1--;
        }
        if (l1 != -1) {
            ans += 1LL * rmq(l[i].second + 2, n);
        }
    }
    cout << ans << endl;
    return 0;
}