#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval {
    int l, m, r;
    bool drop=0, cl;
    Interval() {}
    Interval(int l, int m, int r, bool c): l(l), m(m), r(r), cl(c) {}
};

struct Intervals {
    vector<Interval> intv;
    void add(int m, int r, bool c=1) {intv.eb(intv.back().r, m, r, c);}
    void add(int l, int m, int r, bool c=0) {intv.eb(l, m, r, c);}
    int process(int x) {
        int rem=0, ans=0;
        rep(i, intv.size()) {
            if(!intv[i].cl) rem=intv[i].l;
            ans+=(intv[i].m+intv[i].r+rem)/x;
            rem=min((intv[i].m+intv[i].r+rem)%x, intv[i].r);
            if(intv[i].l+intv[i].m+intv[i].r<=x) {
                intv[i].drop=1; //drop smaller sizes
            }
        }
        rep(i, (int)intv.size()-1) if(intv[i].drop) intv[i+1].cl=0;
        vector<Interval> oth;
        for(auto& it: intv) if(!it.drop) oth.pb(it);
        intv.swap(oth);
        return ans;
    }
};

int32_t main() {
    fastio;
    int n; cin>>n;
    string s; cin>>s;
    int j=-1;
    rep1(i, n-1) {
        if(s[i]=='?'&&j==-1) j=i;
        if(s[i]!='?'&&j!=-1) {
            if(s[i]==s[j-1]) {
                for(int k=j; k<i; k++) s[k]=s[i];
            }
            j=-1;
        }
    }
    Intervals f;
    int l=0, p=0; while(p<n&&s[p]=='?') p++, l++;
    if(p==n) {
        rep1(i, n) cout<<n/i<<' '; cout<<endl;
        return 0;
    }
    while(p<n) {
        int m=0, r=0;
        char c=s[p];
        while(p<n&&s[p]==c) p++, m++;
        while(p<n&&s[p]=='?') p++, r++;
        if(l!=-1) f.add(l, m, r), l=-1;
        else f.add(m, r);
    }
    rep1(i, n) cout<<f.process(i)<<' '; cout<<endl;
}