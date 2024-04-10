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

int n, k;
bool check_odd(int m, vector <int> &a) {
    //all odd <= m
    int cnt = 0;
    for (auto e : a) {
        if (e <= m || cnt%2==0) {
            ++cnt;
        }   
    }   
    return cnt >= k;
}   

bool check_even(int m, vector <int> &a) {
    int cnt = 0;
    for (auto e : a) {
        if (e <= m || cnt%2==1) {
            ++cnt;
        }   
    }   
    return cnt >= k;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> k;

    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    const int INF = 1e9+7;
    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check_odd(m, a) || check_even(m, a))
            r = m;
        else
            l = m;
    }       
    cout << r << endl;
}