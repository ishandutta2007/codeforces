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


const int maxN = 200001;
int n;
string s;
int c[maxN];
int p[maxN];
int cn[maxN];
int where[maxN];
int who[maxN];
int lcp[maxN];
vector<int> g;
vector<int> x[maxN];
int k = 0;
int h[maxN];
int w[maxN];
long long f[maxN];



int main() {
 	cin >> s;
 	s += 'a' - 1;
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
 	}
 	for (int h = 0; (1 << h) < n; h++) {
 		k = (1 << h);
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
 			lcp[where[i]] = x;
 		}
 	}
 	long long ans = 1LL * (n - 1) * n / 2LL;
 	int k = n - 2;
 	n = 0;
 	h[n] = -1;
    w[n] = 0;
    f[n] = 0;
    n++;
    for (int i = 0; i < k; i++) {
        int l = 1;
        while (h[n - 1] >= lcp[i + 1]) {
        	l += w[--n];
        }
        w[n] = l;
        h[n] = lcp[i + 1];
        f[n] = f[n - 1] + 1LL * l * lcp[i + 1];
        n++;
        ans += f[n - 1];
    }
    cout << ans << endl;
    return 0;
}