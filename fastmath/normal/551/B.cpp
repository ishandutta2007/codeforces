#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int K = 26;

int cnta[K], cntb[K], cntc[K];
int ost[K];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    string a, b, c;
    cin >> a >> b >> c;

    for (char t : a) {
        ++cnta[t - 'a'];
    }   
    for (char t : b) {
        ++cntb[t - 'a'];
    }   
    for (char t : c) {
        ++cntc[t - 'a'];
    }   

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (int t = 0; t < K; ++t) {
            ost[t] = cnta[t] - cntb[t] * i;
        }   

        bool ch = 1;
        for (int t = 0; t < K; ++t) {
            ch &= (ost[t] >= 0);
        }
        if (!ch) {
            break;
        }   

        int add = MAXN;
        for (int t = 0; t < K; ++t) {
            if (cntc[t]) {
                add = min(add, ost[t] / cntc[t]);
            }
        }   

        ans = max(ans, i + add);
    }   

    for (int i = 0; i < MAXN; ++i) {
        for (int t = 0; t < K; ++t) {
            ost[t] = cnta[t] - cntb[t] * i;
        }
           
        bool ch = 1;
        for (int t = 0; t < K; ++t) {
            ch &= (ost[t] >= 0);
        }
        if (!ch) {
            break;
        }   
        
        int add = MAXN;
        for (int t = 0; t < K; ++t) {
            if (cntc[t]) {
                add = min(add, ost[t] / cntc[t]);
            }
        }   

        if (i + add == ans) {
            for (int t = 0; t < i; ++t) {
                cout << b;
            }   
            for (int t = 0; t < add; ++t) {
                cout << c;
            }   
            for (int t = 0; t < K; ++t) {
                int x = cnta[t] - cntb[t] * i - cntc[t] * add;
                for (int k = 0; k < x; ++k) {
                    cout << (char)('a' + t);
                }   
            }   
            cout << '\n';
            exit(0);
        }   
    }   

    return 0;
}