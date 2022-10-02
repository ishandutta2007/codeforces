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
#include <unordered_map>
#include <cassert>


using namespace std;



int n;
vector<int> s;
int c[200000];
int p[200000];
int cn[200000];
int where[200000];
int who[200000];
int lcp[200000][19];
vector<int> g;
vector<int> x[200000];
int m, kk;
string a[200000];
vector<int> pos[100001];
int st[200001];
int who1[200001];
int ss = 1;
vector<int> T[525000];
unordered_map<int, int> last;


int rmq(int l, int r) {
    int k = st[r - l + 1];
    int ss = (1 << k);
    return min(lcp[l][k], lcp[r - ss + 1][k]);
}


int rmq1(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return lower_bound(T[v].begin(), T[v].end(), l) - T[v].begin();
    }
    return rmq1(v * 2, vl, (vl + vr) / 2, l, r) + rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


bool good(int i, int j, int k) {
    int l = pos[i][j];
    int l1 = l;
    int r1 = n - 1;
    while (l1 != r1) {
        int m1 = (l1 + r1 + 1) / 2;
        //cout << l1 << ' ' << r1 << endl;
        if (m1 == l || rmq(l, m1 - 1) >= k - j + 1) {
            l1 = m1;
        } else {
            r1 = m1 - 1;
        }
    }
    int r2 = l1;
    l1 = l;
    r1 = 0;
    while (l1 != r1) {
        int m1 = (l1 + r1) / 2;
        if (m1 == l || rmq(m1, l - 1) >= k - j + 1) {
            l1 = m1;
        } else {
            r1 = m1 + 1;
        }
    }
    int l2 = l1;
    return rmq1(1, 1, ss, l2 + 1, r2 + 1) >= kk;
}


int main() {
    cin >> m >> kk;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        pos[i].resize((int)a[i].size());
        for (int j = 0; j < (int)a[i].size(); j++) {
            pos[i][j] = (int)s.size();
            who1[(int)s.size()] = i;
            s.push_back(a[i][j] - 'a');
        }
        s.push_back(26 + i);
    }   
    n = (int)s.size();
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(s[i], i));
    }
    sort(v.begin(), v.end());
    int classes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            classes++;
        }
        c[v[i].second] = classes - 1;
        p[i] = v[i].second;
    }
    for (int h = 0; (1 << h) < n; h++) {
        int k = (1 << h);
        vector<pair<pair<int, int>, int> > v1;
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[(p[i] + k) % n]].push_back(p[i]);
        }
        vector<int> pn;
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < (int)x[i].size(); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        for (int i = 0; i <= classes; i++) {
            x[i].clear();
        }
        for (int i = 0; i < n; i++) {
            x[c[p[i]]].push_back(p[i]);
        }
        pn.clear();
        for (int i = 0; i < classes; i++) {
            for (int j = 0; j < (int)x[i].size(); j++) {
                pn.push_back(x[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            p[i] = pn[i];
        }
        vector<int> cn;
        classes = 0;
        cn.resize(n);
        for (int i = 0; i < n; i++) { 
            if (i == 0 || (c[p[i]] != c[p[i - 1]] || (c[(p[i] + k) % n] != c[(p[i - 1] + k) % n]))) {
                classes++;
            } 
            cn[p[i]] = classes - 1;
        }   
        for (int i = 0; i < n; i++) {
            c[i] = cn[i];
        }
    }
    for (int i = 0; i < n; i++) {
        where[p[i]] = i;
        who[i] = p[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = max(0, x - 1);
        if (where[i] != n - 1) {
            int j = who[where[i] + 1];
            for (int g = i + x; g < n; g++) {
                if ((g - i + 1 > n - j)) {
                    break;
                }
                if (s[g] != s[j + (g -  i)]) {
                    break;
                }
                x++;
            }
            lcp[where[i]][0] = x;
        }
    }
    for (int k = 1; k <= 18; k++) {
        for (int i = 0; i < n; i++) {
            lcp[i][k] = min(lcp[i][k - 1], lcp[min(i + (1 << (k - 1)), n - 1)][k - 1]);
        }
    }
    int ss1 = 1;
    int cnt = 0;
    for (int i = 1; i <= 200000; i++) {
        if (ss1 * 2 <= i) {
            ss1 *= 2;
            cnt++;
        }
        st[i] = cnt;
    }
    ss = 1;
    while (ss < n) {
        ss *= 2;
    }
    for (int i = 0; i < n; i++) {
        T[ss + i].push_back(last[who1[p[i]]]);
        last[who1[p[i]]] = i + 1;
    }
    for (int i = ss - 1; i >= 1; i--) {
        if (T[i * 2].empty() && T[i * 2 + 1].empty()) {
            continue;
        }
        if (T[i * 2].empty()) {
            T[i] = T[i * 2 + 1];
            continue;
        }
        if (T[i * 2 + 1].empty()) {
            T[i] = T[i * 2];
            continue;
        }
        T[i].resize((int)T[i * 2].size() + (int)T[i * 2 + 1].size());
        merge(T[i * 2].begin(), T[i * 2].end(), T[i * 2 + 1].begin(), T[i * 2 + 1].end(), T[i].begin());
    }
    for (int i = 0; i < m; i++) {
        int l = -1;
        long long ans = 0;
        for (int j = 0; j < (int)a[i].size(); j++) {
            pos[i][j] = where[pos[i][j]];
            l = max(l, j - 1);
            while (l + 1 < (int)a[i].size() && good(i, j, l + 1)) {
                l++;
            }
            if (j <= l) {
                ans += l - j + 1;
              //  cout << i + 1 << ' ' << j + 1 << ' ' << l + 1 << endl;
            } 
        }
        printf("%I64d ", ans);
    }
    printf("\n");
    return 0;
}