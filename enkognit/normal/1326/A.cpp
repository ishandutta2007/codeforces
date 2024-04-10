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

ll n, T, kl = 0, m, ans, p, w, b[2000001];
ll a[1000001];
vector<ll> c[100001];
vector<ll> v;
bool tt[1000001];
int tl[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1) cout << "-1\n"; else
        {
            cout << 2;
            for (int i = 1; i < n; i++) cout << "3";
            cout << "\n";
        }
    }
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