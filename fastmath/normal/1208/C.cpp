#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int N = 2007;
int a[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int ptr = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            for (int x = i; x <= i + 1; ++x) {
                for (int jj = j; jj <= j + 1; ++jj) {
                    a[x][jj] = ptr++;    
                }
            }   
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}