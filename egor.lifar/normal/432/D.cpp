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


#define M 1000000007
#define P 424243


int n;
string s;
int c[100002];
int p[100002];
int cn[100002];
int where[100002];
int who[100002];
int lcp[100002];
vector<int> g;
vector<int> x[100002];
int k = 0;
int d[500000];
int  p1[100002];
int  h[100001];


bool les(int a, int b) {
    return c[a] < c[b] || (c[a] == c[b] && c[(a + k) % n] < c[(b + k) % n]);
}


void change(int i, int x) {
    d[i] = x;
    while (i > 0) {
        i /= 2;
        d[i] = min(d[i * 2], d[i * 2 + 1]);
    }
}


int gethash(int l, int r) {
    return (h[r] - (l > 0 ? 1LL * h[l - 1] * p1[r - l + 1]: 0) % M + M) % M;
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vr < l || vl > r) {
        return 1000 * 1000 * 1000;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    int vm = (vl + vr)  / 2;
    return min(rmq(v * 2, vl, vm, l, r), rmq(v * 2 + 1, vm + 1, vr, l, r));
}


int spusk(int v, int vl, int vr, int l, int x) {
    if (vr < l) {
        return -1;
    }
    if (d[v] >= x) {
        return -1;
    }
    if (vl == vr) {
        return vl - 1;
    }
    if (vl >= l) {
        if (d[v] >= x) {
            return -1;
        }
        if (d[v * 2] < x) {
            return spusk(v * 2, vl, (vl + vr) / 2, l, x);
        }
        return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
    }
    int t = spusk(v * 2, vl, (vl + vr) / 2, l, x);
    if (t != -1) {
        return t;
    }
    return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
}


int spusk1(int v, int vl, int vr, int l, int x) {
    if (vl > l) {
        return -1;
    }
     if (d[v] >= x) {
        return -1;
    }
    if (vl == vr) {
        return vl - 1;
    }
    if (vr <= l) {
        if (d[v] >= x) {
            return -1;
        }
        if (d[v * 2 + 1] < x) {
            return spusk1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
        }
        return spusk1(v * 2, vl, (vl + vr) / 2, l, x);
    }
    int t = spusk1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, x);
    if (t != -1) {
        return t;
    }
    return spusk1(v * 2, vl, (vl + vr) / 2, l, x);
}



int main() {
    cin >> s;
   // cout << s << endl;
    s += 'Z' + 1;
    n = (int)s.size();
    vector<pair<char, int> > v;
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
    //  cout << c[v[i].second] << endl;
        //cout << p[i] + 1 << endl;
    }
    for (int h = 0; (1 << h) < n; h++) {
        k = (1 << h);
        vector<pair<pair<int, int> , int> > v1;
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
    //      cout << p[i] << endl;
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
        //cout << p[i] + 1 << endl;
        g.push_back(p[i]);
    }
  //  return 0;
    //aaba
    //aba
    //ba
    //a
    for (int i = 0; i < n; i++) {
        //cout << c[i] << endl;
        where[g[i]] = i;
        who[i] = g[i];
    }
    int x = 0;
    int ss = 1;
    while (ss < n) {
        ss *= 2;
    }
    for (int i = 0; i < n; i++) {
        x = max(0, x - 1);
        if (where[i] != n - 1) {
            int j = who[where[i] + 1];
            for (int g = i + x; g < n; g++) {
                if ((g - i + 1 > n - j)) {
                    break;
                }
                if (s[g] != s[j + (g - i)]) {
                    break;
                }
                x++;
            }
            lcp[where[i]] = x;
            change(ss + where[i], x);
        }
    }
    vector<pair<int, int> > ans;
    p1[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (1LL * p1[i - 1] * P) % M;
    }
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) % M + s[i]) % M;
    }
    for (int i = 0; i < n - 1; i++) {
        if (gethash(0, i) != gethash(n - 2 - i, n - 2)) {
            continue;
        }
        int g = where[0];
        int anss = 1;
        //cout << who[38] << endl;
       // cout << g << endl;
        if (g != n - 1 && lcp[g] >= i + 1) {
            // int l = g;
            // int r = n - 2;
            // while (l != r) {
            //     int m = (l + r + 1) / 2;
            //     if (rmq(1, 1, ss, g + 1, m + 1) < i + 1) {
            //         r = m - 1;
            //     } else {
            //         l = m;
            //     }
            // }
            int sh = spusk(1, 1, ss, g + 1, i + 1);
            if (sh == -1) {
                sh = n - 1;
            }
         //   cout << sh << endl;
           //cout << who[g + 2] << endl;
          //  cout << g << ' ';
        //    cout << sh << endl;
            anss += sh - g;
         //   cout << g + 1 << ' ' << l + 1 << endl;
        }

       // cout << g + 1 << endl;
     //   cout << anss << endl;
        if (g != 0 && lcp[g - 1] >= i + 1) {
            // int l = g;
            // int r = 0;
            // while (l != r) {
            //     int m = (l + r + 1) / 2;
            //     if (rmq(1, 1, ss, m + 1, g + 1) < i + 1) {
            //         r = m + 1;
            //     } else {
            //         l = m;
            //     }
            // }
            int sh = spusk1(1, 1, ss, g, i + 1);
          //  if (sh == -1) {
            //    sh = 0;
           // }
          //  cout << sh << endl;
            anss += g - 1 - sh;
        }
    //    cout << anss << endl;
        ans.push_back(make_pair(i + 1, anss));
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}