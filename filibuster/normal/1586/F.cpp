//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


void solve() {
    int n, k;
    cin >> n >> k;
    
    int cnt = 0;
    /*int n1 = n;
    
    while(n1 > 1) {
        cnt++;
        n1 /= k;
    }*/
    
    //cout << cnt << endl;
    
    {
        int p = 1;
        for(cnt = 1; ; cnt++){
            p *= k;
            if((n - 1) / p == 0)
                break;
            
        }
            
    }
    
    cout << cnt << endl;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int p = 1;
            for(int cl = 1; ; cl++) {
                p *= k;
                if(i / p == j / p) {
                    cout << cl << ' ';
                    break;
                }
            }
                
        }
    }
    
    
    /*int cnt = (n + k - 1) / k;
    
    cout << cnt << endl;
    
    
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << (i / k == j / k ? cnt : j / k) << ' ';
        }
    }
    cout << endl;*/

    /*int m = 0;
    for(int i = 1; i <= n; i++) {
//        if(n / i + (n % i > 1) <= k) {
        if((n + i - 1) / i < k + 1) {
            m = i;
            break;
        }
    }

    cout << m + 1 << endl;
    int sz = (n + m - 1) / m;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << (i / sz == j / sz) << ' ';
        }
    }
    cout << endl;*/
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();

}