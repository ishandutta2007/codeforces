#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, a[500005], b[500005];
string s, d;
vector <ll> c[500005];
map <ll, ll> t;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n;
    ll l=0, r=0;
    for (int i = 0; i< n; i++)
    {
        cin >> a[i];
        if (a[i]%2) l=1; else r=1;
    }
    if (l && r) sort(a,a+n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/