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
int ptr[N];
ii ed[N];
struct Edge {
    int c;
    bool in;
    int i; 
} a[N];  
bool comp(Edge a, Edge b) {
    return (a.c < b.c) || (a.c == b.c && a.in > b.in);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].c >> a[i].in;
        a[i].i = i;       
    }   
    sort(a, a + m, comp);
    for (int i = 1; i <= n; ++i)
        ptr[i] = 1;
    int cnt = 1, cur = 1;
    for (int i = 0; i < m; ++i) {
        if (a[i].in) {
            ed[a[i].i] = mp(cnt, cnt + 1);
            ++cnt;
        }   
        else {
            while (ptr[cur] >= cur - 1 && cur <= cnt)
                ++cur;            
            if (cur > cnt) {
                cout << "-1" << endl;
                exit(0);
            }   
            ed[a[i].i] = mp(cur, ptr[cur]);
            ++ptr[cur];
        }   
    }   
    for (int i = 0; i < m; ++i)
        cout << ed[i].f << ' ' << ed[i].s << endl;
}