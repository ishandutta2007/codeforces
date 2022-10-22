#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
const int N = 101;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }   
    int mx = a[0];
    vector <int> ans;
    ans.app(0);
    for (int i = 1; i < n; ++i) {
        if (a[i] * 2 <= a[0]) {
            mx += a[i];
            ans.app(i);
        }   
    }  
    if (mx * 2 <= sum) {
        cout << "0\n";
    }   
    else {
        cout << ans.size() << '\n';
        for (int e : ans) cout << e + 1 << ' ';
        cout << '\n';
    }   
}