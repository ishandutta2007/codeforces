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

ll n, m, k, ans[1000001], TT, l, T, i, j, h;
ll a[1000001], b[1000001];
string s, d;
bool tt[2000001];
vector <ll> v;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sort(s.begin(),s.end());
        ll o=0, tw=0, sum=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]=='0') o++; else
            if ((s[i]-'0')%2==0) tw++;
            sum+=s[i]-'0';
        }
        if (o>1) tw++;
        if (sum%3==0 && tw && o) {cout << "red\n";} else cout << "cyan\n";
    }
    return 0;
}