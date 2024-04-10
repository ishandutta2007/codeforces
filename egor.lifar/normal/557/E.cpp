#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


#define M 1000000007
#define P 424243


string s;
bool good[5000][5000];
int tt[5002];
int kk = 0;
int c[1000000];
int p[1000000];
int cn[1000000];
int n;
vector<int> x[1000000];
int k = 0;
int h[5002];
int p1[5002];
unordered_map<int, int> m;


bool les(int a, int b) {
    return c[a] < c[b] || (c[a] == c[b] && c[(a + k) % n] < c[(b + k) % n]);
}


int gethash(int l, int r) {
    return (h[r] - (l > 0 ? 1LL * h[l - 1] * p1[r - l + 1]: 0) % M + M) % M;
}


int main() {
    cin >> s;
    cin >> kk;
    n = (int)s.size();
    for (int k1 = 1; k1 <= n; k1++) {
        for (int i = 0; i <= n - k1; i++) {
            int j = i + k1 - 1;
            if (i == j) {
                good[i][j] = true;
                continue;
            }
            if ((j - i + 1) <= 4) {
                good[i][j] = (s[i] == s[j]);
                continue;
            }
            good[i][j] = good[i + 2][j - 2] & (s[i] == s[j]);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << good[i][j];
    //     }
    //     cout << endl;
    // }
    p1[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (1LL * p1[i - 1] * P) % M;
    }   
    for (int i = 0; i < n; i++) {
        h[i] = ((i > 0 ? 1LL * h[i - 1]: 0) * P + s[i]) % M;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (good[i][j]) {
                m[gethash(i, j)]++;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            tt[i] += good[i][j];
        }
       // cout << tt[i] << endl;
    }
    s += 'c';
    n++;
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
    for (int i = 0; i < n - 1; i++) {
        //cout << tt[p[i]] << endl;
       // cout << p[i] << endl;
        string ans;
        for (int j = p[i]; j < n - 1; j++) {
            ans += s[j];
            if (good[p[i]][j]) {
              //  cout << m[gethash(p[i], j)] << endl;
                if (kk > m[gethash(p[i], j)]) {
                    kk -= m[gethash(p[i], j)];
                    m[gethash(p[i], j)] = 0;
                } else {
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    return 0;       
}