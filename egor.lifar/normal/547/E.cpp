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


const int maxN = 400002;
int n;
vector<int> s;
int c[maxN];
int p[maxN];
int cn[maxN];
int where[maxN];
int who[maxN];
int lcp[maxN][20];
vector<int> g;
vector<int> x[maxN];
int m;
string a[maxN];
int pos[maxN];
int who1[maxN];
vector<int> T[maxN * 4];
int ss = 1;
    

int rmq(int l, int r) {
    if (l > r) {
        return 1000000000;
    }
    int ss1 = 1;
    int cnt = 0;
    while (ss1 * 2 <= r - l + 1) {
        ss1 *= 2;
        cnt++;
    }
    return min(lcp[l][cnt], lcp[r - ss1 + 1][cnt]);
}


int rmq1(int v, int vl, int vr, int l, int r, int l1, int r1) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return upper_bound(T[v].begin(), T[v].end(), r1) - lower_bound(T[v].begin(), T[v].end(), l1); 
    }
    return rmq1(v * 2, vl, (vl + vr) / 2, l, r, l1, r1) + rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, l1, r1);
}



int main() {
    int q;
    cin >> m >> q;
 	for (int i = 0; i < m; i++) {
        cin >> a[i];
        pos[i] = (int)s.size();
        for (int j = 0; j < (int)a[i].size(); j++) {
            s.push_back(a[i][j] - 'a');
            who1[(int)s.size() - 1] = i + 1;
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
    int n1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[p[i]] >= 26) {
            n1 = i;
            break;
        }
    }
    ss = 1;
    while (ss < n1) {
        ss *= 2;
    }
 	for (int i = 0; i < n; i++) {
 		where[p[i]] = i;
 		who[i] = p[i];
        if (i < n1) {
            T[ss + i].push_back(who1[p[i]]);
        }
 	}
 	int x = 0;
    for (int i = ss - 1; i >= 0; i--) {
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
        T[i].resize(T[i * 2].size() + T[i * 2 + 1].size());
        merge(T[i * 2].begin(), T[i * 2].end(), T[i * 2 + 1].begin(), T[i * 2 + 1].end(), T[i].begin());
    }
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
            if (where[i] < n1) {
 			    lcp[where[i]][0] = x;
            }
 		}
 	}
    for (int k = 1; k <= 19; k++) {
        for (int j = 0; j < n1; j++) {
            lcp[j][k] = min(lcp[j][k - 1], lcp[min(j + (1 << (k - 1)), n1 - 1)][k - 1]);
        }
    }
    for (int i = 0; i < m; i++) {
        pos[i] = where[pos[i]];
    }
    for (int i = 0; i < q; i++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        k--;
        int p = pos[k];
        int l2 = p;
        int r2 = n1 - 1;
        while (l2 != r2) {
            int m = (l2 + r2 + 1) / 2;
            if (p == m || rmq(p, m - 1) >= (int)a[k].size()) {
                l2 = m;
            } else {
                r2 = m - 1;
            }
        }
        int r1 = l2;
        l2 = p;
        r2 = 0;
        while (l2 != r2) {
            int m = (l2 + r2) / 2;
            if (p == m || rmq(m, p - 1) >= (int)a[k].size()) {
                l2 = m;
            } else {
                r2 = m + 1;
            }
        }
        int l1 = l2;
        //cout << l1 << ' ' << r1 << endl;
        printf("%d\n", rmq1(1, 1, ss, l1 + 1, r1 + 1, l, r));
    }
    return 0;
}