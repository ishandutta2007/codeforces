#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair

const int N = 101;
bool a[2][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    int cnt = 0;
    for (int i = 0; i < n; ++i) 
        cnt += a[0][i] && !a[1][i];
    int c2 = 0;
    for (int i = 0; i < n; ++i)
        c2 += a[1][i] && !a[0][i];    
    if (!cnt) {
        cout << "-1" << endl;
        exit(0);
    }   
    cout << c2 / cnt + 1 << endl;
}