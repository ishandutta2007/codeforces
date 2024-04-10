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

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, T, i, j, h, a[N];
bool tt[1000001];
string s, d;

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
        vector <ll> v;
        for (int i = 0; i < s.size(); i++) tt[i]=0;
        for (int i = 0; i < s.size(); i++)
            if (s[i]=='o')
            {
                if (i>1 && s[i-2]=='t' && s[i-1]=='w')
                {
                    if (i==s.size()-1 || s[i+1]!='o')
                        v.pb(i+1), tt[i]=1; else
                        v.pb(i), tt[i-1]=1;
                }else
                if (i<s.size()-2 && s[i+1]=='n' && s[i+2]=='e')
                {
                    if (i==0 || s[i-1]!='o')
                        v.pb(i+1), tt[i]=1; else v.pb(i+2),tt[i+1]=1;
                }
            }
        cout << v.size() << "\n";
        for (int i = 0 ;i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}