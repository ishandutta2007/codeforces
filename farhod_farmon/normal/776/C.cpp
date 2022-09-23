#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const ll N = 100100;
const ll MX = 1e16;
const ll MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll k;
ll a[N];
ll s[N];
vector < ll > v;
map < ll, ll > used;

void solve()
{
    cin >> n >> k;
    if(abs(k) > 1){
        for(ll i = 1; i < MX; i *= k)
            v.pb(i);
    }
    else{
        if(k == -1)
            v.pb(-1);
        v.pb(1);
    }
    ll cnt = 0;
    used[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
        for(ll x: v)
            if(used.find(s[i] - x) != used.end())
                cnt += used[s[i] - x];
        used[s[i]]++;
    }
    cout << cnt << endl;
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}