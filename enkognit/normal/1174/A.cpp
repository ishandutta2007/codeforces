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
    ll k=0, l=0;
    for (int i = 0; i < n*2; i++)
    {
        cin >> a[i];
        k+=a[i];
    }
    sort(a, a+n*2);
    for (int i = 0; i < n; i++) l+=a[i];
    if (l*2==k) cout << -1; else
    {
        for (int i = 0; i < n*2; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/