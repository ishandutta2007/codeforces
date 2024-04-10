#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

const int N = 111111;
const int MOD = 1e9+7;
const int INF = 1e9;

int n, a[N], n1[N], n2[N], mx;

vector<int> b[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    set<pair<int, int> > s1, s2;
    for (int i = 0; i < n; i++) {
        set<pair<int, int> >::iterator j = s1.upper_bound(make_pair(a[i], -INF));
        if (j == s1.end()) {
            int sz = s1.size();
            s1.insert(make_pair(a[i], sz+1));
            n1[i] = sz+1;
        } else {
            int num = j->second;
            s1.erase(j);
            s1.insert(make_pair(a[i], num));
            n1[i] = num;
        }
    }
    mx = s1.size();
    for (int i = n-1; i >= 0; i--) {
        set<pair<int, int> >::iterator j = s2.upper_bound(make_pair(-a[i], -INF));
        if (j == s2.end()) {
            int sz = s2.size();
            s2.insert(make_pair(-a[i], sz+1));
            n2[i] = sz+1;
        } else {
            int num = j->second;
            s2.erase(j);
            s2.insert(make_pair(-a[i], num));
            n2[i] = num;
        }
    }
    for (int i = 0; i < n; i++) {
        if (n1[i]+n2[i] == mx+1) {
            b[n1[i]].push_back(i);
        }
        //cerr << n1[i] << ' ' << n2[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        assert(b[n1[i]].size() != 0);
        if (n1[i]+n2[i] != mx+1) {
            cout << "1";
        } else {
            if (b[n1[i]].size() > 1) cout << "2";
            else cout << "3";
        }
    }
    return 0;
}