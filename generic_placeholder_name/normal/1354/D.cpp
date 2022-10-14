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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

const int MAX_VAL = 1000010;

void update(int i, int add, vector<int>& BIT)
{
    while (i > 0 && i < BIT.size())
    {
        BIT[i] += add;
        i = i + (i & (-i));
    }
}

int sum(int i, vector<int>& BIT)
{
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i = i - (i & (-i));
    }

    return ans;
}

int query(int k, vector<int> &BIT)
{
    int l = 0;
    int h = BIT.size();
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (k <= sum(mid, BIT))
            h = mid;
        else
            l = mid+1;
    }

    return l;
}

int del=0, ins=0;
void insert(int x, vector<int> &BIT)
{
    ins++;
    update(x, 1, BIT);
}

void erase(int x, vector<int> &BIT)
{
    del++;
    update(x, -1, BIT);
}

int32_t main(){
    fastio;
    int n, q; cin>>n>>q;
    vi a(MAX_VAL);
    rep(i, n) {int x; cin>>x; insert(x, a);}
    while(q--) {
        int k; cin>>k;
        if(k>=0) insert(k, a);
        else erase(query(-k, a), a);
    }
    if(del==ins) cout<<"0\n";
    else cout<<query(1, a)<<endl;
}