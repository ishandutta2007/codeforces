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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

bool comp(const string& a, const string& b) {
    if(a.length()<b.length()) return true;
    else if(a.length()>b.length()) return false;
    else return a<b;
}

string solve(int n, int k);

string solve_last(int n) {
    if(n<=8) return to_string(n);
    else return solve(n-8, 0)+"8";
}

const string INF="11111111111111111111111111111111111111111";
string solve(int n, int k) {
    if(k==0) {
        if(n<=9) return to_string(n);
        else return solve(n-9, k)+"9";
    }
    else {
        ++k;
        string ans=INF;
        rep(y, 10) {
            string mx=INF, cur=to_string(y);
            //we have last digit = y, number is A*10+y
            //f(A) = sum of digits of A
            int m=min(10-y, k);
            int take=0; rep(i, k) take+=(y+i)%10;
            if(n<take) continue;
            //n = take + m * f(A) + (k-m) * f(A+1)
            //we iterate through the number of ending 9s of A, cap = 0->15
            rep(cap, 15) {
                int rem=n-take-9*m*cap-k+m;
                if(rem<0||rem%k!=0) continue;
                rem/=k;
                string res=solve_last(rem);
                rep(i, cap) res+='9'; res+=cur;
                reverse(all(res)); while(res.back()=='0'&&res.size()>1) res.pop_back();
                reverse(all(res));
                //cout<<n<<' '<<k-1<<' '<<y<<' '<<cap<<' '<<rem<<' '<<res<<endl;
                if(comp(res, mx)) mx=res;
            }
            if(comp(mx, ans)) ans=mx;
        }
        if(ans==INF) return "-1";
        else return ans;
    }
}

int32_t main() {
    fastio;
    //freopen("gen.txt", "w", stdout);
    //rep1(i, 150) rep(j, 9) cout<<i<<' '<<j<<' '<<solve(i, j)<<endl;
    int q; cin>>q;
    while(q--) {
        int n, k; cin>>n>>k;
        cout<<solve(n, k)<<endl;
    }
}