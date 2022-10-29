#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, T, i, j, h;
ll a[1000001], b[1000001];
string s, d;
bool tt[2000001];
ll c[100001], g[1000001];
map<int,int> w;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> s;
        cin >> d;
        for (int i = 0; i < 26; i++) g[i]=0;
        for (int i = 0; i < s.size(); i++) g[s[i]-'a']++;
        for (int i = 0; i < 26; i++) c[i]=0;
        for (int i = 0; i < s.size(); i++) c[d[i]-'a']++;
        bool t=0;
        //d+=(char)('z'+1);
        if (s.size()>d.size()) {cout << "NO\n";continue;}
        for (int i = 0; i < d.size()-s.size()+2; i++)
        {
            bool tt=1;
            //cout << i << "\n";
            for (int j = 0; j < 26; j++) {if (c[j]!=g[j]) tt=0;}
            if (tt) {t=1;break;}
            if (i==d.size()-s.size()) break;
            c[d[i]-'a']--;c[d[i+s.size()]-'a']++;
            //cout << i << " " << i+s.size() << "\n";
        }
//cout << "\n";
        if (t) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}