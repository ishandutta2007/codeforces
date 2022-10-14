#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int cnt[26] = {0};
        for(char c: s) cnt[c - 'a']++;
        if(count(cnt, cnt + 26, 0) == 25) {
            cout << s << endl;
            continue;
        }
        bool ok = 0;
        rep(i, 26) if(cnt[i] == 1) {
            sort(all(s));
            s.erase(find(all(s), i + 'a'));
            s = char(i + 'a') + s;
            cout << s << endl;
            ok = 1; break;
        }
        if(ok) continue;
        int fi = 0;
    	while(!cnt[fi]) fi++;
    	string ans;
    	if(cnt[fi] * 2 - 2 <= s.size()) {
            ans.pb(fi + 'a');
            ans.pb(fi + 'a');
            cnt[fi] -= 2;
            rep(i, s.size() - 2) {
                if((i & 1) && cnt[fi]) ans.pb(fi + 'a'), cnt[fi]--;
                else {
                    rep(j, 26) if(cnt[j] && j != fi) {
                        ans.pb(j + 'a');
                        cnt[j]--;
                        break;
                    }
                }
            }
    	}
    	else {
            int se = fi + 1;
            while(!cnt[se]) se++;
            ans.pb(fi + 'a');
            ans.pb(se + 'a');
            cnt[fi]--; cnt[se]--;
            if(cnt[fi] + cnt[se] + 2 == s.size()) {
                rep(i, cnt[se]) ans.pb(se + 'a');
                rep(i, cnt[fi]) ans.pb(fi + 'a');
            }
            else {
                rep(i, cnt[fi]) ans.pb(fi + 'a');
                for(int i = se + 1; i < 26; i++) if(cnt[i]) {
                    ans.pb(i + 'a');
                    cnt[i]--;
                    break;
                }
                for(int i = se; i < 26; i++) rep(j, cnt[i]) ans.pb(i + 'a');
            }
        }
        cout << ans << endl;
	}
}