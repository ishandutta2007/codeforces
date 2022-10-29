#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, v, r, p, k, ans, a[10001];
string s;
map<ll,ll> t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> v;
    v=min(n,v);
    cout << (n-v)*(n-v+1)/2+v-1;
    return 0;
}