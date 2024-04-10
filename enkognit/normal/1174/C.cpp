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
ll t[100001];

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n;
    ll p=0;
    for (int i = 2; i <= sqrt(n); i++)
        if (!t[i])
        {
            ll j=i*i;
            p++;
            t[i]=p;
            for (; j <= n; j+=i) t[j]=p;
        }
    for (int i = 2; i <= n; i++)
    {
        if (!t[i]) p++, t[i]=p;
        cout << t[i] << " ";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/