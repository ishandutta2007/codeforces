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
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200222;



int t;
int n;
int d[MAXN];
string s;
int c[MAXN];
int last[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> t;
    for (int it = 0; it < t; it++) {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            d[i] = s[i] - '0';
            c[i] = 2;
        }
        for (int i = 0; i <= 10; i++) {
            last[i] = -1;
        }
        vector<int> g;
        int uk = 0;
        for (int i = 0; i < n; i++) {
            last[d[i]] = i;
        }   
        vector<int> st;
        for (int i = 0; i < n; i++) {
            st.pb(d[i]);
        }
        sort(all(st));
        for (int i = 0; i < n; i++) {
            if (d[i] == st[uk]) {
                c[i] = 1;
                g.pb(i);
                uk++;
            }
        }
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (c[i] == 2) {
                if (!g.empty() && d[g.back()] > d[i]) {
                    bad = true;
                    break;
                }
                g.pb(i);
            }
        }
        if (bad) {
            cout << '-' << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                cout << c[i];
            }
            cout << '\n';
        }
    }
    return 0; 
}