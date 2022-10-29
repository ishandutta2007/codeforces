#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 210000;

int n, k, s, m;
bool fail;
set<pii> cur;
pii cnt, c2;
vector<pii> ans, nxt;

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

        cin >> n >> s;
        forn(i, n) {
                scanf("%d", &k);
                cur.insert(make_pair(-k, i + 1));
        }
                
        fail = 0;
        while (!cur.empty()) {
                cnt = *cur.begin();
                cur.erase(cur.begin());
                m = abs(cnt.first);
                forn(i, m) {
                        if (cur.empty()) {
                                fail = 1;
                                break;
                        }
                        c2 = *cur.begin();
                        cur.erase(cur.begin());
                        c2.first++;
                        ans.push_back(make_pair(c2.second, cnt.second));
                        if (c2.first != 0) nxt.push_back(c2);
                }
                if (fail) break;
                
                forn(i, nxt.size())
                     cur.insert(nxt[i]);
                nxt.clear(); 
        }

        if (fail)
                cout << "No";
        else {
                cout << "Yes" << endl;
                cout << ans.size() << endl;
                forn(i, ans.size())
                        printf("%d %d\n", ans[i].fi, ans[i].se); 
        }

    return 0;
}