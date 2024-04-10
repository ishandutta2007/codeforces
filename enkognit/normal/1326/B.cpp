#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl = 0, m, ans, p, w, b[1000001];
ll a[1000001];
vector<ll> c[100001];
vector<ll> v;
bool tt[1000001];
int tl[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll k = 0;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + k;
        k = max(k, a[i]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
/*
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/