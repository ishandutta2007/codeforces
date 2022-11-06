#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll sum = 0;
        vector<ll> pos;
        vector<ll> neg;
        for(ll i = 1; i <= n; i++)
        {
            ll ta;
            cin >> ta;
            sum += ta;
            if(ta > 0)
                pos.pb(ta);
            else
                neg.pb(ta);
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        reverse(neg.begin(), neg.end());
        if(sum == 0)
            cout << "NO\n";
        else
        if(sum > 0)
        {
            cout << "YES\n";
            while(!pos.empty())
            {
                cout << pos.back() << " ";
                pos.pop_back();
            }
            while(!neg.empty())
            {
                cout << neg.back() << " ";
                neg.pop_back();
            }
            cout << "\n";
        }
        else
        {
            cout << "YES\n";
            while(!neg.empty())
            {
                cout << neg.back() << " ";
                neg.pop_back();
            }
            while(!pos.empty())
            {
                cout << pos.back() << " ";
                pos.pop_back();
            }
            cout << "\n";
        }
    }
}