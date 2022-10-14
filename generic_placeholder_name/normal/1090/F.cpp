#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//actually i think i have a solution
//that is worst case 2n
//but expected perf is about n + log n + 10

constexpr int N=1005;
int c[N];
gp_hash_table<int, int> m[N][N];
gp_hash_table<int, int> v;

void ask(int x, int y, int z) {
    if(m[x][y].find(z)!=m[x][y].end()) return;
    cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
    int ret; cin>>ret;
    m[x][y][z]=m[x][z][y]=m[y][x][z]=m[y][z][x]=m[z][x][y]=m[z][y][x]=ret;
}

int l1, l2, s;
int eq1=-1, eq2=-1; //the random doesn't work in case of equality but brute asking does
void solve_5(int p) {
    for(int i=p; i<p+5; i++) {
        for(int j=p; j<i; j++) {
            for(int k=p; k<j; k++) {
                ask(i, j, k);
            }
        }
    }
    int a[5]={p, p+1, p+2, p+3, p+4};
    sort(a, a+5, [&](int x, int y) -> bool {
            for(int i=p; i<p+5; i++) {
                for(int j=p; j<i; j++) {
                    if(m[i][j].find(x)!=m[i][j].end()&&m[i][j].find(y)!=m[i][j].end()) {
                        if(m[i][j][x]<m[i][j][y]) return 1;
                        if(m[i][j][x]>m[i][j][y]) return 0;
                    }
                }
            }
            return 0;
         });
    l1=a[4];
    l2=a[3];
    s=a[0];
    int s[5][5];
    for(int i=0; i<5; i++) {
        for(int j=i+2; j<5; j++) {
            s[i][j]=m[a[i]][a[i+1]][a[j]];
        }
    }
    int r[5];
    r[0]=((s[0][2]+s[2][4]+s[0][4])-2*s[2][4])/2;
    r[2]=((s[0][2]+s[2][4]+s[0][4])-2*s[0][4])/2;
    r[4]=((s[0][2]+s[2][4]+s[0][4])-2*s[0][2])/2;
    r[1]=s[1][4]-r[4];
    r[3]=s[0][3]-r[0];
    for(int i=0; i<5; i++) c[a[i]]=r[i], v[r[i]]=a[i];
    for(int i=0; i<4; i++) if(r[i]==r[i+1]) {
        eq1=a[i]; eq2=a[i+1];
        break;
    }
}

void itr(int p) {
    if(~eq1) {
        ask(eq1, eq2, p);
        c[p]=m[eq1][eq2][p]-c[eq1];
        return;
    }
    ask(l1, l2, p);
    if(m[l1][l2][p]<c[l1]+c[l2]) {
        c[p]=m[l1][l2][p]-c[l1];
        if(c[p]<c[s]) s=p;
    }
    else if(m[l1][l2][p]>c[l1]+c[l2]) {
        c[p]=m[l1][l2][p]-c[l2];
        l2=l1; l1=p;
    }
    else {
        ask(s, l2, p);
        c[p]=m[s][l2][p]-c[s];
        l2=p;
    }
    if(v.find(c[p])!=v.end()) eq1=v[c[p]], eq2=p;
    else v[c[p]]=p;
}

int32_t main() {
    //fastio;
    int n; cin>>n;
    int p=1;
    solve_5(1);
    vi idx;
    for(int i=6; i<=n; i++) idx.pb(i);
    shuffle(all(idx), rng);
    for(int i: idx) itr(i);
    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<c[i]<<' ';
    cout<<endl;
}