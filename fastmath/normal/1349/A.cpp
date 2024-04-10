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

int get(vector <int> &a, int p) {
    vector <int> b;
    for (int e : a) {
        int pw = 0;
        while (e % p == 0) {   
            ++pw;
            e /= p;            
        }
        b.app(pw);
    }   
    sort(all(b));

    int ans = 1;
    for (int i = 0; i < b[1]; ++i)
        ans *= p;
    return ans;
}   

vector <int> getp(int n) {
    vector <int> ans;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            ans.app(p);
            while (n % p == 0)
                n /= p;
        }   
    }   
    if (n > 1)
        ans.app(n);
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector <int> p;
    for (int i = 0; i < 2; ++i) {
        for (int e : getp(a[i]))
            p.app(e);
    }   
    sort(all(p));
    p.resize(unique(all(p)) - p.begin());

    int ans = 1;
    for (int e : p)
        ans *= get(a, e);
    cout << ans << endl;
}