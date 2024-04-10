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

ll n, m, k, ans, TT, l, T, i, j, h, pp=0;
ll a[2000001];
bool tt[2000001];
vector <ll> c[1000001], v;
string s, d;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 1; i <= n; i++) {a[i]=s[i-1]-'0';}
    vector <ll> v;
    v.pb(0);
    for (int i = 1; i <= k; i++) v.pb(a[i]);
    bool tt=0, t=0;
    for (int i = 1; i <= n; i++)
    {
        ll o=i%k;
        if (o==0) o=k;
        if (a[i]>v[o] && !t) tt=1;
        if (a[i]<v[o]) t=1;
    }
    if (tt)
    {
        for (int i = v.size()-1; i > -1; i--)
        {
            v[i]++;
            if (v[i]==10) v[i]=0;
            if (v[i]!=0) {break;}
        }
        //if (o) reverse(v.begin(),v.end()),v.pb(1),reverse(v.begin(),v.end());
    }
    cout << n << "\n";
    for (int i = 1; i <= n; i++)
    {
        ll o=i%k;
        if (o==0) o=k;
        cout << v[o];
    }
    return 0;
}