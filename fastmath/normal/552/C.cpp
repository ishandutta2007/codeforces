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

int w, n;
vector <int> a;
void gen(int i, int sum) {
    if (sum == n) {
        cout << "YES\n";
        exit(0);
    }   
    if (i == a.size())
        return;
    gen(i + 1, sum - a[i]);
    gen(i + 1, sum);
    gen(i + 1, sum + a[i]);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> w >> n;
    if (w <= 3) {
        cout << "YES\n";
        exit(0);
    }   

    const int INF = 1e12;

    int c = 1;
    for (int i = 0; i < 16; ++i) {
        a.app(c);
        c *= w;        
        if (c > INF)
            break;
    }   
    
    gen(0, 0);
    cout << "NO\n";
}