#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int l = 0;
    int r = n - 1;
    bool inv = false;
    vector<int> s(n);
    for (int i = 0; i < n; i++) a[i] = 1;
    for (int i = 0; i < n; i++) s[i] = i + 1;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;
        if (x == 1){
            int d;
            cin >> d;
            if (d + d > r - l + 1){
                d = r - l + 1 - d;
                inv = !inv;
            }
            if (inv){
                int S = 0;
                for (int j = 0; j < d; j++){
                    a[r - d - d + 1 + j] += a[r - j];
                    s[r - j] += S;
                    S += a[r - j];
                    s[r - d - d + 1 + j] += S;
                }
                r -= d;
            } else {
                int S = 0;
                for (int j = 0; j < d; j++){
                    a[l + d + d - 1 - j] += a[l + j];
                    s[l + d + d - 1 - j] -= S;
                    S += a[l + j];
                    s[l + j] -= S;
                }
                l += d;
            }
        } else {
            int L, R;
            cin >> L >> R;
            R--;
            if (inv){
                L = r - L;
                R = r - R;
                swap(L, R);
            } else {
                L = l + L;
                R = l + R;
            }
            if (L == 0) cout << s[R] << "\n"; else cout << s[R] - s[L - 1] << "\n";
        }
    }
    
    return 0;
}