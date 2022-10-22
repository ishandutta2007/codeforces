#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
int n, m;
bool have[1 << 8];
const int N = 3e5 + 7;
int a[N][8];
bool check(int x) {
    memset(have, 0, sizeof have);
    for (int i = 0; i < n; ++i) {
        int ms = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] >= x)
                ms += 1 << j;
        }   
        have[ms] = 1;
    }                       
    for (int i = 0; i < (1 << m); ++i)
        for (int j = 0; j < (1 << m); ++j)
            if ((i | j) == ((1 << m) - 1) && have[i] && have[j])
                return 1;
    return 0;
}
int who[1 << 8];   
void print(int x) {
    for (int i = 0; i < n; ++i) {
        int ms = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] >= x)
                ms += 1 << j;
        }   
        who[ms] = i + 1;
    }
    for (int i = 0; i < (1 << m); ++i)
        for (int j = 0; j < (1 << m); ++j)
            if ((i | j) == ((1 << m) - 1) && who[i] && who[j]) {
                cout << who[i] << ' ' << who[j] << endl;
                exit(0);
            }   
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    int l = 0;
    int r = 1e9 + 7;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }   
    print(l);
}