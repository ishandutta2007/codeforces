//#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/stack:32777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

int t, n, a, b;

int main()
{
    cin >> t;
    FOR (tst,0,t) {
        cin >> n >> a >> b;
        if (a + b > n-2 || abs(a-b) > 1) {
            cout << "-1\n";
            continue;
        };
        int l = 1, r = n;
        int mx;
        if (a >= b) {mx = 1; cout << 1 << " "; l++;}
        else {mx = 0; cout << n << " "; r--;}
        
        while (l <= r) {
            if (mx) {
                if (a) cout << r-- << " ", mx^=1, a--;
                else { FOR (i,l,r+1) cout << i << " "; l = r+1; }
            } else {
                if (b) cout << l++ << " ", mx^=1, b--;
                else { RFOR (i,r+1,l) cout << i << " "; l = r+1; }
            }
        }
        cout << "\n";
    }
    return 0;
}