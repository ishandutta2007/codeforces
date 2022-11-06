#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, a[NN], x[NN];
pair<ll, ll > A[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(ll j = 30; j >= 0; j--)
            if(a[i] & (1 << j))
                x[j]++;
    }
    for(ll i = 1; i <= n; i++)
    {
        ll z = 0;
        for(ll j = 30; j >= 0; j--)
            if((a[i] & (1 << j)) && (x[j] == 1))
                z += (1 << j);
        A[i] = mp(z, a[i]);
    }
    sort(A + 1, A + 1 + n);
    reverse(A + 1, A + 1 + n);
    for(ll i = 1; i <= n; i++)
        cout << A[i].se << " ";
}