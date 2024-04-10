#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define tm stanislavpolyn

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kl, x, y, b[1000001], a[2000001], c[1000001];
ld ans;
pll bn[200001][21];
map<int, int> tt;
string s;
vector <pll> v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll kl=0, p=0, w=0;
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        p++;
        if (a[i]>0)
        {
            if (tt[a[i]]==0) kl++; else {cout << "-1\n";exit(0);}
            tt[a[i]]=1;
        } else
        {
            a[i]=-a[i];
            if (tt[a[i]]==1) kl--; else {cout << "-1\n";exit(0);}
            tt[a[i]]=2;
        }
        if (kl==0) {v.pb(p);tt={};w+=p;p=0;}
    }
    if (w!=n) {cout << "-1\n";exit(0);}
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}