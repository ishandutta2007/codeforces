#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll n, q, hz;
ll a[3][NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while(q--)
    {
        ll ta, tb;
        cin >> ta >> tb;
        ll rev = 1;
        if(ta == 1)
            rev = 2;
        if(a[ta][tb] == 0)
        {
            a[ta][tb] = 1;
            hz += a[rev][tb + 1];
            hz += a[rev][tb];
            hz += a[rev][tb - 1];
        }
        else
        {
            a[ta][tb] = 0;
            hz -= a[rev][tb + 1];
            hz -= a[rev][tb];
            hz -= a[rev][tb - 1];
        }
        if(hz)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}