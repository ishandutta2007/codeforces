#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e3 + 5;
ll t, n;
pair<ll, ll> A[NN];
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            A[i] = mp(ta, tb);
        }
        sort(A + 1, A + 1 + n);
        s = "";
        ll bisa = 1;
        for(ll i = 1; i <= n; i++)
            if(A[i - 1].fi > A[i].fi || A[i - 1].se > A[i].se)
            {
                bisa = 0;
                break;
            }
            else
            {
                for(ll j = A[i - 1].fi; j < A[i].fi; j++)
                    s += "R";
                for(ll j = A[i - 1].se; j < A[i].se; j++)
                    s += "U";
                // s += "x";
                // cout << A[i].fi << " " << A[i].se << "_\n";
            }
        if(bisa)
            cout << "YES\n" << s << "\n";
        else
            cout << "NO\n";
    }
}