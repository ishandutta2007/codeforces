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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=6e5+10, K=20; //idk why correct, will take it though
int a[N+1], pf[N+1];
int t[N+1][K+1];
int lg[N+1];

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) {
        int x; cin>>x;
        a[x]++;
    }
    rep1(i, N) pf[i]=pf[i-1]+a[i];
    rep1(i, N) t[i][0]=a[i]?i:0;
    rep1(j, K) {
        for(int i=1; i+(1<<j)<=N; i++) {
            t[i][j]=max(t[i][j-1], t[i+(1<<(j-1))][j-1]);
        }
    }
    lg[1]=0;
    for(int i=2; i<=N; i++) lg[i]=lg[i>>1]+1;
    auto query_max = [&](int l, int r) -> int {
        if(r<l) return 0;
        int j=lg[r-l+1];
        return max(t[l][j], t[r-(1<<j)+1][j]);
    };
    ll ans=0;
    for(int y=2; y<=N; y++) {
        ll amt=0;
        int blk=N/y+1;
        int f[blk], s[blk];
        for(int k=0; k<=N; k+=y) {
            int nxt=min(N, k+y-1);
            int c=k/y;
            amt+=c*1LL*(pf[nxt]-pf[k-1]);
            int tmp=query_max(k, nxt);
            if(!tmp) f[c]=s[c]=0;
            else if(a[tmp]>=2) f[c]=s[c]=tmp;
            else f[c]=tmp, s[c]=query_max(k, tmp-1);
            if(f[c]) f[c]-=k;
            if(s[c]) s[c]-=k;
        }
        int l=1, r=N;
        while(l<r) {
            int m=(l+r+1)/2;
            int c=INT_MAX;
            if(2*m<=N&&pf[N]-pf[2*m-1]>=1) {
                int mx=0;
                for(int i=(2*m)/y; i<blk; i++) mx=max(mx, f[i]);
                if(mx>=(2*m)%y) c=(2*m)/y;
                else c=(2*m)/y+1;
            }
            if(pf[N]-pf[m-1]>=2) {
                int fm=0, sm=0;
                int nxt=min((m/y+1)*y-1, N);
                fm=query_max(m, nxt);
                if(!fm) {}
                else if(a[fm]>=2) sm=fm;
                else sm=query_max(m, fm-1);
                if(fm) fm-=(m/y)*y;
                if(sm) sm-=(m/y)*y;
                for(int i=m/y+1; i<blk; i++) {
                    if(fm<f[i]) fm=f[i];
                    else if(sm<f[i]) sm=f[i];
                    if(fm<s[i]) fm=s[i];
                    else if(sm<s[i]) sm=s[i];
                }
                int rm=2*(m/y);
                if(fm<m%y) rm++;
                if(sm<m%y) rm++;
                c=min(c, rm);
            }
            if(amt-c>=m) l=m;
            else r=m-1;
        }
        if(l>1) ans=max(ans, 1LL*r*y);
    }
    cout<<ans<<endl;
}