#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = (1 << 18);

int n;
string str;
vector <int> classes[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    cin >> str;

    vector <pair <int, pair<int, int> > > eq(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        eq[i].fs = int(str[i] - 'a');
        eq[i].sc.fs = 0;
        eq[i].sc.sc = i;        
    }
    sort(eq.begin(), eq.end());

    for (int i = 1; i <= n; i++) {
        vector <pair <pair <int, int>, pair <int, int> > > neq;
        for (int j = 0; j < (1 << n); j++) {
            classes[j].clear();
        }
        for (int j = 0; j < (1 << n); j += (1 << (i - 1))) {
            classes[j].resize(1 << (i - 1));
        }
        for (int j = 0; j < (int) eq.size(); j++) {
            classes[eq[j].sc.sc][eq[j].sc.fs] = eq[j].fs;            
        }
        
        for (int j = 0; j < (1 << n); j += (1 << i)) {
            for (int k = 0; k < (1 << (i - 1)); k++) {
                neq.pb(mp(mp(classes[j][k], classes[j + (1 << (i - 1))][k]), mp(k, j)));
                neq.pb(mp(mp(classes[j + (1 << (i - 1))][k], classes[j][k]), mp(k + (1 << (i - 1)), j)));
            }
        }        
        sort(neq.begin(), neq.end());

        int lb = 0;
        int rb = 0;
        int ccnt = 0;
        eq.clear();
        while (lb < (1 << n)) {
            rb = lb + 1;
            while (rb < (1 << n) && neq[rb].fs == neq[lb].fs) {
                rb++;
            }
            for (int k = lb; k < rb; k++) {
                eq.pb(mp(ccnt, neq[k].sc));
            }
            ccnt++;
            lb = rb;
        }
    }

    int res = eq[0].sc.fs;
    cerr << res << endl;
    for (int i = 0; i < (1 << n); i++) {
        cout << str[i ^ res];
    }
    cout << endl;

    return 0;
}