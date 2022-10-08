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
#include <random>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 100 * 1000 + 10;
const int sqb = 500;
const int htsize = 200 * 1000 + 7;

int n;
int a[maxn];
int cnt[maxn * 4 + 1];
int htcnt[htsize];
int htvalue[htsize];

int process(int x) {
    int p = x % htsize;
    p = (p + htsize) % htsize;
    while (htvalue[p] != maxn && htvalue[p] != x) {
        p++;
        if (p == htsize) {
            p = 0;
        }
    }    
    htvalue[p] = x;
    htcnt[p]++;

    return htcnt[p];
}

int main() {
    /*
    mt19937 mt;

    freopen("input.txt", "w", stdout);
    cout << 100 * 1000 << endl;
    for (int i = 0; i < 100 * 1000; i++) {
        cout << int(mt() % (200 * 1000 + 1)) - 100 * 1000 << ' ';
    }
    cout << endl;

    return 0;

    */
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    double start = clock();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    
    cerr << (clock() - start) / CLOCKS_PER_SEC << endl;

    int ans = max(0, n - 2);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(n, i + sqb); j++) {
            int delta = a[j] - a[i];
            if (delta % (j - i) == 0) {
                int d = delta / (j - i);
                cnt[d + 2 * maxn]++;
                ans = min(ans, n - 1 - cnt[d + 2 * maxn]);
            }
        }    
        for (int j = i + 1; j < min(n, i + sqb); j++) {
            int delta = a[j] - a[i];
            if (delta % (j - i) == 0) {
                int d = delta / (j - i);
                cnt[d + 2 * maxn]--;
            }
        }
    }
    
    cerr << (clock() - start) / CLOCKS_PER_SEC << endl;

    for (int d = -sqb; d <= sqb; d++) {
        for (int i = 0; i < htsize; i++) {
            htvalue[i] = maxn;
            htcnt[i] = 0;
        }        
        for (int i = 0; i < n; i++) {
            int init = a[i] - d * i;
            ans = min(ans, n - process(init));
        }
    }
    

    cout << ans << endl;

    cerr << (clock() - start) / CLOCKS_PER_SEC << endl;

    return 0;
}