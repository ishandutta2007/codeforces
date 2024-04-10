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

int sum(int n) {
    return n * (n + 1) / 2;
}   
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans = 0;
    for (int i = C; i <= D; ++i) {

        int l = max(i - B, B);
        int r = min(i - A, C);
        if (l <= r) {
            ans += (B - i) * (r - l + 1);
            ans += sum(l, r);
        }   
        ans += max(0ll, B - A + 1) * max(0ll, C - max(B, i + 1 - A) + 1);
    }   
    cout << ans << endl;
}