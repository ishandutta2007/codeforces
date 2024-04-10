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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ptr = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= ptr) 
            continue;
        ++l;
        ptr = a[i] + 2;
    }   
    cout << l << endl;
    ptr = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        ptr = max(ptr, a[i] - 1);
        if (ptr <= a[i] + 1) {
            ++r;
            ++ptr;
        }   
    }   
    cout << r << endl;
}