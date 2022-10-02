/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 1000228;



int n, w;
long long s[MAXN];
int a[MAXN];
long long add[MAXN];
map<int, vector<pair<int, int> > > ft;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
    	int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> a[j];
            int ll = j;
            int rr = w - (l - j);
            ft[ll].pb({a[j], 0});
            ft[rr + 1].pb({a[j], 1});
        }
        ft[0].pb({0, 0});
        ft[w - l].pb({0, 1});
        ft[l].pb({0, 0});
        ft[w].pb({0, 1});
        multiset<int> ss;
        int last = -1;
        int pt = 0;
        for (auto x: ft) {
            if (last != -1) {
                add[pt] += last;
                add[x.first] -= last;
            }
            for (auto z: x.second) {
                if (z.second == 0) {
                    ss.insert(z.first);
                } else {
                    ss.erase(ss.find(z.first));
                }
            }
            if (!ss.empty()) {
                int f = *ss.rbegin();
                last = f;
            }
            pt = x.first;
        }
        ft.clear();
    }
    long long cur = 0;
    for (int i = 0; i < w; i++) {
        cur += add[i];
        cout << cur << ' ';
    }
    cout << '\n';
    return 0;  
}