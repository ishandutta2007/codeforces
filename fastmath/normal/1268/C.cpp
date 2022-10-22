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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
int a[N], p[N], n;
int f[N];
void add(int i) {
    for (; i < N; i |= i + 1) ++f[i];
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i)
        ans += f[i];
    return ans;
}      
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        p[a[i]] = i;
    }    
    int inv = 0;
    set <int> ms;
    set <int> :: iterator t;
    int sum = 0, suml = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        int x = n - p[i];
        inv += get(x);
        add(x);

        sum += p[i];
        if (ms.empty()) {
            ms.insert(p[i]);
            t = ms.begin();
        }   
        else {
            if (p[i] < *t) {
                ++l;
                suml += p[i];
            }   
            ms.insert(p[i]);
            while (l > ms.size() / 2) {
                --l;
                --t;
                suml -= *t;
            }   
            while (l < ms.size() / 2) {
                suml += *t;
                ++l;
                ++t;
            }   
        }   
        int r = ms.size() - l - 1;
        int sumr = sum - suml - *t;
        int ans = inv;
        ans += (*t - 1) * l - suml - (l - 1) * l / 2;
        ans += (sumr - r) - (*t) * r - (r - 1) * r / 2;

        //cout << (*t - 1) * l - suml - (l - 1) * l / 2 << ' ' << (sumr - r) - (*t) * r - (r - 1) * r / 2 << '\n';
        cout << ans << ' ';
    }   
    cout << '\n';
}