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
#define sqr(a) ((a)*(a))

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, T, ans, i, j, h, a[1000001], b[1010101], TT;
vector <ll> v;
string s, d;

string get_mask(ll h)
{
    ll x=h;
    string s;
    while (x)
    {
        s+=(char)(x%2+'0');
        x/=2;
    }
    return s;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll sm=0, xro=0;
        for (int i = 1; i <= n; i++) {cin >> a[i];sm+=a[i];xro^=a[i];}
        if (2*xro==sm) {cout << "0\n";continue;}
        xro*=2;
        for (ll i = 0; i <= 1e18; i=max(i*2,1ll))
            if (xro^(i*2)>=sm+i)
        {
            //if (n==2)cout << i << "\n";
            ll r=i, sum=sm, xr=xro;
            sum+=r;
            xr=xr^(r*2);
            if (sum%2)
            {
                sum-=r;
                xr=xr^(r*2);
                r++;
                sum+=r;
                xr=xr^(r*2);
            }
            if (xr<sum || (xr-sum)%2 || ((sm+r+xr-sum)!=(xro^(r*2)))) {continue;}
            cout << "3\n";
            cout << (xr-sum)/2 << " " << (xr-sum)/2 << " " << r << "\n";
            break;
        }
    }
    return 0;
}
/*
3
0 0 2
8 10 3
16 0 3

2
0 0 1
6 0 1

*/