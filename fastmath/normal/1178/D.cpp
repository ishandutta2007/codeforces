#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back

const int N = 2007;
bool p[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    
    for (int i = 2; i < N; ++i) {
        p[i] = 1;
    }   
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            for (int j = i * 2; j < N; j += i) {
                p[j] = 0;
            }   
        }   
    }   
    
    int n;
    cin >> n;
    for (int add = 0; add <= (n / 2); ++add) {
        if (p[n + add]) {
            cout << n + add << '\n';
            cout << 1 << ' ' << n << '\n';
            for (int i = 1; i + 1 <= n; ++i) {
                cout << i << ' ' << i + 1 << '\n';
            }   
            int m = n / 2;
            for (int i = 1; i <= add; ++i) {
                cout << i << ' ' << m + i << '\n';
            }   
            exit(0);
        }
    }   

}