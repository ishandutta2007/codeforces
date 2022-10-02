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



map<char, int> cnt;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto x: s) {
        cnt[x]++;
    }
    int ts = 0;
    int ts1 = 0;
    for (int i = n; i >= 0; i--) {
        if (cnt['o'] >= i && cnt['n'] >= i && cnt['e'] >= i) {
            int j = n - i * 3;
            if (j % 4 == 0) {
                int t = j / 4;
                if (cnt['z'] >= t && cnt['e'] >= i + t && cnt['r'] >= t && cnt['o'] >= i + t) {
                    ts = i;
                    ts1 = t;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < ts; i++) {
        cout << 1 << ' ';
    }
    for (int i = 0; i < ts1; i++) {
        cout << 0 << ' ';
    }
    cout << endl;
    return 0; 
}