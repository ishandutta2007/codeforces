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

const int N = 101;
string ar[N];

int n, m;
int getrow(int i) {

    bool bad = 1;
    for (int j = 0; j < m; ++j)
        bad &= ar[i][j] == 'P';
    if (bad)
        return N;

    int a = 0;
    bool c = 1;
    for (int j = 0; j < m; ++j)
        c &= ar[i][j] == 'A';
    if (c) 
        a = 0;
    else if (ar[i][0] == 'A' || ar[i].back() == 'A')
        a = 1;
    else
        a = 2;

    int b = 0;

    c = 1;
    for (int i1 = 0; i1 < i; ++i1) 
        for (int j = 0; j < m; ++j)
            c &= ar[i1][j] == 'A';    
    b += !c;

    c = 1;
    for (int i1 = i + 1; i1 < n; ++i1) 
        for (int j = 0; j < m; ++j)
            c &= ar[i1][j] == 'A';        
    b += !c;

    return a + b;
}   

string t[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int ts; cin >> ts;
    while (ts--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> ar[i];
        int ans = N;
        for (int i = 0; i < n; ++i) 
            ans = min(ans, getrow(i));

        for (int i = 0; i < m; ++i) {
            t[i] = "";
            for (int j = 0; j < n; ++j)
                t[i] += ar[j][i];    
        }
        for (int i = 0; i < m; ++i)
            ar[i] = t[i];
        swap(n, m);

        for (int i = 0; i < n; ++i)
            ans = min(ans, getrow(i));
        if (ans == N) cout << "MORTAL\n";
        else cout << ans << '\n';
    }   
}